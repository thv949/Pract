#include <iostream>
#include <string>
#include "Menu.h"
#include "time.h"


Menu Menu::create(std::istream& in)
{
    std::string input;
    std::getline(in, input, ' ');

    Menu menu;

    menu.SetName(input);

    if (std::getline(in, input, ' ')) {
        menu.SetPrice(input); 

        int HH, MM;
        char colon = ':';
        if (in >> HH >> colon >> MM) { 
            Time menu_time;
            menu_time.SetTime(HH, MM); 
            menu.SetMenuTime(menu_time); 
            in.ignore();
        }
    }

    return menu;
}

std::string Menu::GetName() const {
    return name;
}

void Menu::SetName(const std::string& name) {
    this->name = name;
}

std::string Menu::GetPrice() const {
    return price;
}

void Menu::SetPrice(const std::string& price) {
    this->price = price;
}

Time Menu::GetMenuTime() const
{
    return this->menu_time;
}
void Menu::SetMenuTime(const Time& time)
{
    this->menu_time = time;
}

void Menu::ReadMenu(std::istream& in) {
    std::string input_name;
    if (std::getline(in, input_name, ' ')) {
        this->SetName(input_name); 

        double input_price;
        if (in >> input_price) {
            this->SetPrice(std::to_string(input_price));
            Time menu_time;
            menu_time.ReadTime(in);
            this->SetMenuTime(menu_time);
            in.ignore();
        }
    }
}

void Menu::WriteMenu() const {
    std::cout << "Название блюда: " << this->GetName() << std::endl;
    std::cout << "Цена: " << this->GetPrice() << std::endl; 
    this->GetMenuTime().WriteTime();
}

Menu::Menu(const std::string& n, const std::string& p, const Time& t) : name(n), price(p), menu_time(t) {}

bool Menu::ValidateName(const std::string& name) {
    static const std::string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФКЦЧШЩЪЫЬЭЮЯ"
        "0123456789"
        "_";
    for (char ch : name) {
        if (alphabet.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void Menu::InvalidName(const std::string& name)
{
    static const std::string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФКЦЧШЩЪЫЬЭЮЯ"
        "0123456789"
        "_";

    if (name.empty() || !ValidateName(name) || name.find_first_not_of(alphabet) != std::string::npos) {
        throw std::runtime_error("Invalid name!");
    }
    ValidateName(name);
}
bool Menu::ValidatePrice(const double& price)
{
    if (price <= 0) {
        return false;
    }
    return true;
}

void Menu::InvalidPrice(const double& price)
{
    if (price < 0)
    {
        throw std::runtime_error("Invalid price!");
    }
    ValidatePrice(price);
}
