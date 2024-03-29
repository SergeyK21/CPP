#include <iostream>
#include <src/Car.h>
#include <sstream>

using namespace auto_car;

int main()
{
    setlocale(LC_ALL, "Russian");
    // ������� ������ *car � *lorry
    Car *car = new Car();
    Lorry *lorry = new Lorry();
    // ������� ��������� ����� ��� ������������ ������� get, set � �������������� ���������� >> ������ Lorry
    std::istringstream iss("����� 8 178 14");
    iss >> *lorry;
    // ������� ��������� ����� ��� ������������ ������� get, set � �������������� ���������� >> ������ Car
    std::istringstream iss1("���� 4 78");
    iss1 >> *car;
    // ��������� ������������� �������� << ������ Car � ������ Lorry
    std::cout << *car << std::endl;
    std::cout << *lorry << std::endl;
    // ��������� ��� �������� ����������� ����������:
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