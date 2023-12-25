#pragma once
#include <iostream> 

struct Time {
    int mm;
    int hh;

    void SetMinutes(int minutes);
    void SetHours(int hours);

    int GetMinutes() const;
    int GetHours() const;

    void SetTime(int hours, int minutes); 
    void ReadTime(std::istream& in); 
    void WriteTime(std::ostream& out) const;


   static bool ValidateTime(const std::string& time);
   static void InvalidTime(const std::string& time);

    Time(const int minutes, const int hours);
    Time() : mm(0), hh(0) {}
};

