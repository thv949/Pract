#pragma once
#include <iostream> 

class Time {
private:
    int mm;
    int hh;

public:
    void SetMinutes(int minutes);
    void SetHours(int hours);

    int GetMinutes() const;
    int GetHours() const;

    void WriteTime(std::ostream& out) const;
    void ReadTime(std::istream& in);

    static bool ValidateTime(const std::string& time);
    static void InvalidTime(const std::string& time);

    Time(const int minutes, const int hours);
    Time() : mm(0), hh(0) {}
};
