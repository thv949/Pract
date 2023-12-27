#include "time.h"
#include <iostream> 
#include<sstream>

void Time::SetMinutes(int minutes) {
    mm = minutes;
}

void Time::SetHours(int hours) {
    hh = hours;
}

int Time::GetMinutes() const {
    return mm;
}

int Time::GetHours() const {
    return hh;
}

void Time::ReadTime(std::istream& in) {
    char colon = ':';
    int HH, MM;
    if (in >> HH >> colon >> MM)
    {
        if (colon != ':' || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
            throw std::runtime_error("Неверный формат времени или значения, выходящие за пределы диапазона");
        }
        this->SetHours(HH);
        this->SetMinutes(MM);
    }
}

bool Time::ValidateTime(const std::string& time) {
    std::istringstream in(time);
    int mm, hh;
    char colon = ':';
    in >> hh >> colon >> mm;
    if (in.fail() || hh < 0 || hh > 23 || mm < 0 || mm > 60) {
        return false;
    }
    return true;
}

void Time::InvalidTime(const std::string& time)
{
    if (time.empty() || !ValidateTime(time)) {
        throw std::runtime_error("Invalid time!");
    }
    ValidateTime(time);
}


Time::Time(const int minutes, const int hours) : mm(minutes), hh(hours) {}

void Time::WriteTime(std::ostream& out) const {
    out << "Часов " << this->GetHours() << std::endl;
    out << "Минут " << this->GetMinutes() << std::endl;
}