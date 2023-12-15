#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "time.h"
#include "Read_Output.h"



int main() {

   

    setlocale(LC_ALL, "Russian");
    std::ifstream in("in.txt");
    std::vector<Menu> arr = readMenuFromFile(in);
    PrintMenu(arr);

    in.close();

    return 0;

}