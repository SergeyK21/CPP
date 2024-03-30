#pragma once
#include <string>
#include <iostream>

namespace auto_car
{
    // Класс машин
    class Car
    {
    private:
        // Бренд
        std::string brand_;
        // кол-во цилиндров
        int cylinders_;
        // мощность двигателя
        int power_;
        // статическая переменная класса Car для подсчека кол-ва автомобилей
        static int count_car;

    public:
        // Конструктор
        Car(std::string brand = "", int cylinders = 0,
            int power = 0) : brand_(brand), cylinders_(cylinders), power_(power)
        {
            count_car++;
        }
        // Деструктор
        ~Car()
        {
            count_car--;
        }
        // Методы доступа к private переменной Бренд
        std::string get_brand() { return this->brand_; }
        void set_brand(std::string brand) { this->brand_ = brand; }
        // Методы доступа к private переменной Кол-во цилиндров
        int get_cylinders() { return this->cylinders_; }
        void set_cylinders(int cylinders) { this->cylinders_ = cylinders; }
        // Методы доступа к private переменной Мощность двигателя
        int get_power() { return this->power_; }
        void set_power(int power) { this->power_ = power; }
        // Ststic Метод доступа к private static переменной кол-во автомобилей
        int static get_counts_car() { return count_car; }
        // Перегрузка оператора >>
        friend std::istream &operator>>(std::istream &is, Car &car)
        {
            is >> car.brand_ >> car.cylinders_ >> car.power_;
            return is;
        }
        // Перегрузка оператора <<
        friend std::ostream &operator<<(std::ostream &os, Car &car)
        {
            os << "Бренд - " << car.brand_ << ", кол-во цилиндров - " << car.cylinders_
               << ", мощность - " << car.power_ << " л.с.";
            return os;
        }
    };
    // Дочерний класс Lorry наследует Car
    class Lorry : public Car
    {
    private:
        // Переменная грузоподъемности
        double capacity_;
        // Кол-во грузовиков static переменная
        static int count_lorry;

    public:
        // Конструктор
        Lorry(std::string brand = "", int cylinders = 0,
              int power = 0, double capacity = 0) : Car(brand, cylinders, power), capacity_(capacity)
        {
            count_lorry++;
        }
        // Деструктор
        ~Lorry()
        {
            count_lorry--;
        }
        // Методы доступа к private переменной Грузоподъемность
        double get_capacity() { return this->capacity_; }
        void set_capacity(double capacity) { this->capacity_ = capacity; }
        // Ststic Метод доступа к private static переменной кол-во грузовых автомобилей
        static int get_counts_lorry() { return count_lorry; }
        // Перегрузка оператора >>
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
        // Перегрузка оператора <<
        friend std::ostream &operator<<(std::ostream &os, Lorry &lorry)
        {
            std::string brand = lorry.get_brand();
            int cylinders = lorry.get_cylinders();
            int power = lorry.get_power();
            double capacity = lorry.get_capacity();
            os << "Бренд - " << brand << ", кол-во цилиндров - " << cylinders << ", мощность - " << power
               << " л.с."
               << ", грузоподъемность - " << capacity << " тон";
            return os;
        }
    };
}
