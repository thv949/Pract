#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "time.h" 

struct Menu
{
private:
    std::string name;
    std::string price;
    Time menu_time;

public:
    void create(std::istream& in);

    std::string GetName() const;
    void SetName(const std::string& name);

    std::string GetPrice() const;
    void SetPrice(const std::string& price);

    Time GetMenuTime() const;
    void SetMenuTime(const Time& time);

    void WriteMenu(std::ostream& out = std::cout) const;

    static bool ValidateName(const std::string& name);
    static void InvalidName(const std::string& name);

    static bool ValidatePrice(const double& price);
    static void InvalidPrice(const double& price);

    Menu(const std::string& name, const std::string& price, const Time& time);
    Menu() : name(""), price(""), menu_time() {}
};
