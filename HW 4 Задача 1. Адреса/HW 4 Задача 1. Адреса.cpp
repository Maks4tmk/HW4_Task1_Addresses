// HW 4 Задача 1. Адреса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int home;
    int flat;

public:
    Address() {}

    void set_private_field(std::string city, std::string street, int home, int flat) {
        this->city = city;
        this->street = street;
        this->home = home;
        this->flat = flat;
    }

    std::string get_output_address() {
        return city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(flat);
    }
};


int main()
{
    int size;
    std::ifstream In("in.txt");
    if (!(In.is_open())) {
        std::cout << "Не удалось открыть файл";
    }

    In >> size;

    Address * arr = new Address[size];

    int num = 0;
    std::string city;
    std::string street;
    int home;
    int flat;

    while (!(In.eof())) {
        In >> city;
        In >> street;
        In >> home; 
        In >> flat;
        arr[num].set_private_field(city, street, home, flat);
        num++;
    }

    In.close();

    std::ofstream Out("out.txt");

    Out << size << std::endl;
    for (int i = size - 1; i >= 0; i--) {
        Out << arr[i].get_output_address() << std::endl;
    }

    delete[] arr;

    Out.close();
}

