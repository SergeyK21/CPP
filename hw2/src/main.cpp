#include <Arduino.h>

//Pin включения светодиода
const int led_pin = 39;
//Счетчик нажатия на кнопку
int count_push = 0;
//Флаг включения светодиода
bool light_on = false;

void setup() 
{
  pinMode(led_pin, OUTPUT);
}

void loop() 
{
  //Если на 17м порте максимальное напряжение,
  //то флаг light_on равен "true" и 
  //счетчик нажатия на кнопку увеличивается на 1.
  if(digitalRead(17) == HIGH)
  {
    light_on = true;
    count_push++;
  }

  //Если счетчик нажатия count_push больше или равен 3м,
  //счетчик нажатия на кнопку обнуляется, 
  //флагу light_on приравенивается значение "false",
  //на пине 39 устанавливается максимальное напряжение на 3 сек.
  if(count_push >= 3)
  {
    count_push = 0;
    light_on = false;
    digitalWrite(led_pin, HIGH);
    delay(3000);
    digitalWrite(led_pin, LOW);
  }

  //Если флаг light_on равен "true",
  //флагу light_on приравенивается значение "false",
  //на пине 39 устанавливается максимальное напряжение на 0.5 сек., с прерыванием 0.3 сек., 3 раза.
  if(light_on)
  {
    light_on = false;
    //1
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
    delay(300);
    //2
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
    delay(300);
    //3
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
  }
}
