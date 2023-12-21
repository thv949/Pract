#include "time.h"
#include <iostream> 

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

void Time::SetTime(int hours, int minutes) {
    hh = hours;
    mm = minutes;
}

void Time::ReadTime(std::istream& in) {
    char colon;
    if (in >> hh >> colon >> mm) {
        in.ignore();
    }
}

Time::Time(const int minutes, const int hours) : mm(minutes), hh(hours) {}

void Time::WriteTime() const {
    std::cout << "Время: " << hh << ':' << mm << std::endl;
}
