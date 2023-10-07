#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

struct Menu
{
    string name;
    double price;
    int time;
    Menu() {};
    Menu(const int& time) :
        time(time)
    {
        if (time < 0)
            throw invalid_argument("Bad time");
    }
};

vector<Menu> readMenuFromFile(string filename)
{
    vector<Menu> menu_items;
    ifstream ist(filename);
    if (!ist.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return menu_items;
    }
    while (false == ist.eof())
    {
        Menu menu_item;
        ist >> menu_item.name >> menu_item.price >> menu_item.time;
        menu_items.push_back(menu_item);
    }
    return menu_items;
}

void printMenu(vector<Menu> menu_items)
{
    for (uint64_t i = 0; i < menu_items.size(); ++i)
    {
        cout << menu_items[i].name << " " << menu_items[i].price << " " << menu_items[i].time << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "russian");
    ifstream ist("in.txt");
    vector<Menu> menu_items = readMenuFromFile("in.txt");
    printMenu(menu_items);

    return 0;
}



