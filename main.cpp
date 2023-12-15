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
        std::cout << "Ошибка открытия файла!" << std::endl;
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
        std::cout << "Название блюда: " << dish.name << std::endl;
        std::cout << "Цена: " << dish.price << std::endl;
        std::cout << "Время приготовления: " << dish.menuTime.MM << ":" << dish.menuTime.HH << std::endl;
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

//должно быть так в конце

int main() {
    setlocale(LC_ALL, "russian");
    std::ifstream in("in.txt");
    std::vector<Menu> arr =
        printMenu(arr);
    in.close();
}