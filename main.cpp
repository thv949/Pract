#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "time.h"

using namespace std;

struct Time {
    int MM;
    int HH;
    Time(int m, int h) : MM(m), HH(h) {}
};

struct Menu {
    std::string name;
    std::string price;
    Time menuTime;
   
    Menu(const std::string& n, const std::string& p, const Time& t)
        : name(n), price(p), menuTime(t) {}
};

std::vector<Menu> readMenuFromFile(std::ifstream& in) {
    std::vector<Menu> arr;
    if (!in.is_open()) {
        std::cout << "������ �������� �����!" << std::endl;
        return arr;
    }
    std::string input;
    while (std::getline(in, input, ' ')) {
        std::string name = input;
        if (std::getline(in, input, ' ')) {
            int MM, HH;
            char colon = ':';
            std::string price = input;

            if (in >> MM >> colon >> HH) {
                arr.emplace_back(name, price, Time(MM, HH));
                in.ignore();
            }
        }
    }
    return arr;
}

void printMenu(const std::vector<Menu>& arr) {

    for (const Menu& dish : arr) {
        std::cout << "�������� �����: " << dish.name << std::endl;
        std::cout << "����: " << dish.price << std::endl;
        std::cout << "����� �������������: " << dish.menuTime.MM << ":" << dish.menuTime.HH << std::endl;
}

int main()
{
    setlocale(LC_ALL, "russian");
    std::ifstream in("in.txt");
    std::vector<Menu> arr =
    printMenu(arr);
    in.close();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//������ ���� ��� � �����

int main() {
    setlocale(LC_ALL, "russian");
    std::ifstream in("in.txt");
    std::vector<Menu> arr =
        printMenu(arr);
    in.close();
}