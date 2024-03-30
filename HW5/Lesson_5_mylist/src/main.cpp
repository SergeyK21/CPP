#include <src/MyList.h>
#include <iostream>
#include <src/Car.h>
#include <sstream>
#include <list>

using namespace auto_car;
using namespace mylist;

int main()
{
    setlocale(LC_ALL, "Russian");

    List<Car> cars = List<Car>();
    List<Lorry> lorrys = List<Lorry>();
    for (int i = 0; i < 6; i++)
        if (i % 2 == 0)
        {
            cars.push_front(Car());
        }
        else
        {
            lorrys.push_front(Lorry());
        }
    //Не работают статические переменнае, в остальном все функционирует. 
    std::cout << lorrys[0].get_counts_car() << std::endl;
    for (int i = 0; i < cars.size(); i++)
    {
        std::istringstream iss("ЛАДА 4 78");
        iss>>cars[i];
    }

    for (int i = 0; i < lorrys.size(); i++)
    {
        std::istringstream iss("Камаз 8 178 14");
        iss>>lorrys[i];
    }
        

    for (int i = 0; i < lorrys.size(); i++)
        std::cout << lorrys[i] << std::endl;

    for (int i = 0; i < cars.size(); i++)
        std::cout << cars[i] << std::endl;


    std::cout << cars[0].get_counts_car() << std::endl;
    std::cout << lorrys[0].get_counts_lorry() << std::endl;
    std::cout << "Удалил грузовые автомобили" << std::endl;
    lorrys.clear();
    std::cout << cars[0].get_counts_car() << std::endl;
    // system("pause");
    return 0;
}