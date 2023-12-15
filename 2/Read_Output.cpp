#pragma once

#include "Read_Output.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.h" 

std::vector<Menu> readMenuFromFile(std::ifstream& in) {
    std::vector<Menu> arr;
    if (!in.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return arr;
    }
    std::string input;
    while (std::getline(in, input, ' ')) {
        Menu menu;
        menu.SetName(input);
        if (std::getline(in, input, ' ')) {
            int HH, MM;
            char colon = ':';
            menu.SetPrice(input);
            Time menu_time;
            if (in >> HH >> colon >> MM) {
                menu_time.SetHours(HH);
                menu_time.SetMinutes(MM);
                menu.SetMenuTime(menu_time);
                arr.emplace_back(menu);
                in.ignore();
            }
        }
    }
    return arr;
}

void PrintMenu(const std::vector<Menu>& arr) {
    for (const auto& dish : arr) {
        Time menu_time = dish.GetMenuTime();
        std::cout << "Название блюда: " << dish.GetName() << std::endl;
        std::cout << "Цена: " << dish.GetPrice() << std::endl;
        std::cout << "Время приготовления: " << menu_time.GetHours() << ":" << menu_time.GetMinutes() << std::endl;
    }
}
