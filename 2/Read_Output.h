#pragma once

#include <vector>
#include <fstream>
#include "Menu.h"
#include "time.h"

std::vector<Menu> readMenuFromFile(std::ifstream & in);

void PrintMenu(const std::vector<Menu>& arr);