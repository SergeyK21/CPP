#include <iostream>
#include <src/Car.h>
#include <sstream>

using namespace auto_car;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Создаем адреса *car и *lorry
    Car *car = new Car();
    Lorry *lorry = new Lorry();
    // создаем строковый поток для тестирования методоа get, set и перегруженного опператора >> класса Lorry
    std::istringstream iss("Камаз 8 178 14");
    iss >> *lorry;
    // создаем строковый поток для тестирования методоа get, set и перегруженного опператора >> класса Car
    std::istringstream iss1("ЛАДА 4 78");
    iss1 >> *car;
    // Тестируем перегруженный оператор << класса Car и класса Lorry
    std::cout << *car << std::endl;
    std::cout << *lorry << std::endl;
    // Проверяем как работают статические переменные:
    std::cout << Lorry::get_counts_car() << std::endl;
    std::cout << Lorry::get_counts_lorry() << std::endl;

    std::cout << "__________________" << std::endl;

    delete lorry;
    lorry = nullptr;

    std::cout << Lorry::get_counts_car() << std::endl;
    std::cout << Lorry::get_counts_lorry() << std::endl;

    std::cout << "__________________" << std::endl;

    delete car;
    car = nullptr;

    std::cout << Lorry::get_counts_car() << std::endl;
    std::cout << Lorry::get_counts_lorry() << std::endl;

    // system("pause");
    return 0;
}