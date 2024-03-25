#include <Arduino.h>
#include <string>
#include <vector>

// Pin включения светодиода
#define LED_PIN 39
// Переменная для управления мощностью светодиода
int power = 255;
// Переменная для приема сообщенй из серийного порта
std::string buffer = "";
// Счетчик нажатия на кнопку
int count_push = 0;
// Флаг включения светодиода
bool light_on = false;
// Вектор для храниения последних 4х параметров power
std::vector<int> vector_power = {-1, -1, -1, 255};
// Интервал времени печати параметров в серийный порт
unsigned long time_size = 1000;
// Переменная отсчета интервала времени "time_size" после печати последних 4х параметров power
unsigned long time_temp = 0;
// Метод "mean" прнимает в качестве параметра "vector_power"
// Возвращает среднее значение среди введенных элементов (не более 4х)
int mean(std::vector<int> vector_power)
{
  int count = 0;
  int summ;
  for (int el : vector_power)
    if (el != -1)
    {
      summ += el;
      count++;
    }
  return (int)(summ / count);
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  // Инициализация серийного порта, в качестве аргумента скорость с которой будет работать серйный порт.
  Serial.begin(115200);
}

void loop()
{
  // Функция Serial.available() возвращает значение отличное от 0, если в серийный порт пришла какая-то информация.
  if (Serial.available() > 0)
  {
    buffer = "";
    while (Serial.available() > 0)
    {
      // Serial.read() - функция чтения с серийного порта.
      // Такая запись позволяет прибавить к buffer символьное значение тех ASCII символов,
      // которые прочитали из серийного порта.
      buffer += std::string(1, char(Serial.read()));
      delay(500);
    }
    int param = std::stoi(buffer);
    // Проверка значения мощности "param", оно не может быть менее 0 и более 255
    if ((param >= 0) && (param <= 255))
    {
      power = param;
      // Перестановка значений vector_power [0]=[1], [1]=[2], [2]=[3].
      for (int i = 0; i < (vector_power.size() - 1); i++)
        vector_power[i] = vector_power[i + 1];
      // Присвоение последниму значению vector_power значения power
      vector_power[3] = power;
      Serial.print("Recived power = ");
      Serial.println(power);
    }
  }

  if ((millis() - time_temp) >= time_size)
  {
    Serial.print("Last four parameters (bytes): ");
    // Печать последних 4х параметров
    for (int param : vector_power)
    {
      if (param >= 0)
      {
        Serial.print(param);
        Serial.print(" ");
      }
    }
    Serial.println("");
    // Новая точка отсчета
    time_temp = millis();
  }

  if (digitalRead(17) == HIGH)
    light_on = true;

  if (light_on == true)
  {
    light_on = false;
    // В функцию "analogWrite" в качестве аргумента добавляется результат работы функции mean()
    analogWrite(LED_PIN, mean(vector_power));
    delay(1000);
  }
  else
    analogWrite(LED_PIN, 0);
}
