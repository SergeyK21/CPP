#pragma once
#include <string>
#include <iostream>

namespace auto_car
{
    // ����� �����
    class Car
    {
    private:
        // �����
        std::string brand_;
        // ���-�� ���������
        int cylinders_;
        // �������� ���������
        int power_;
        // ����������� ���������� ������ Car ��� �������� ���-�� �����������
        static int count_car;

    public:
        // �����������
        Car(std::string brand = "", int cylinders = 0,
            int power = 0) : brand_(brand), cylinders_(cylinders), power_(power)
        {
            count_car++;
        }
        // ����������
        ~Car()
        {
            count_car--;
        }
        // ������ ������� � private ���������� �����
        std::string get_brand() { return this->brand_; }
        void set_brand(std::string brand) { this->brand_ = brand; }
        // ������ ������� � private ���������� ���-�� ���������
        int get_cylinders() { return this->cylinders_; }
        void set_cylinders(int cylinders) { this->cylinders_ = cylinders; }
        // ������ ������� � private ���������� �������� ���������
        int get_power() { return this->power_; }
        void set_power(int power) { this->power_ = power; }
        // Ststic ����� ������� � private static ���������� ���-�� �����������
        int static get_counts_car() { return count_car; }
        // ���������� ��������� >>
        friend std::istream &operator>>(std::istream &is, Car &car)
        {
            is >> car.brand_ >> car.cylinders_ >> car.power_;
            return is;
        }
        // ���������� ��������� <<
        friend std::ostream &operator<<(std::ostream &os, Car &car)
        {
            os << "����� - " << car.brand_ << ", ���-�� ��������� - " << car.cylinders_
               << ", �������� - " << car.power_ << " �.�.";
            return os;
        }
    };
    // �������� ����� Lorry ��������� Car
    class Lorry : public Car
    {
    private:
        // ���������� ����������������
        double capacity_;
        // ���-�� ���������� static ����������
        static int count_lorry;

    public:
        // �����������
        Lorry(std::string brand = "", int cylinders = 0,
              int power = 0, double capacity = 0) : Car(brand, cylinders, power), capacity_(capacity)
        {
            count_lorry++;
        }
        // ����������
        ~Lorry()
        {
            count_lorry--;
        }
        // ������ ������� � private ���������� ����������������
        double get_capacity() { return this->capacity_; }
        void set_capacity(double capacity) { this->capacity_ = capacity; }
        // Ststic ����� ������� � private static ���������� ���-�� �������� �����������
        static int get_counts_lorry() { return count_lorry; }
        // ���������� ��������� >>
        friend std::istream &operator>>(std::istream &is, Lorry &lorry)
        {
            std::string brand;
            int cylinders;
            int power;
            double capacity;
            is >> brand >> cylinders >> power >> capacity;
            lorry.set_brand(brand);
            lorry.set_cylinders(cylinders);
            lorry.set_power(power);
            lorry.set_capacity(capacity);
            return is;
        }
        // ���������� ��������� <<
        friend std::ostream &operator<<(std::ostream &os, Lorry &lorry)
        {
            std::string brand = lorry.get_brand();
            int cylinders = lorry.get_cylinders();
            int power = lorry.get_power();
            double capacity = lorry.get_capacity();
            os << "����� - " << brand << ", ���-�� ��������� - " << cylinders << ", �������� - " << power
               << " �.�."
               << ", ���������������� - " << capacity << " ���";
            return os;
        }
    };
}
