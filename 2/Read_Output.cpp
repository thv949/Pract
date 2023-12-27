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
    while (!in.eof()) {
        Menu menu;
        menu.create(in);
        arr.push_back(menu);
    }
    return arr;
}

void PrintMenu(const std::vector<Menu>& arr) {
    for (const auto& dish : arr) {
        dish.WriteMenu();
    }
}
