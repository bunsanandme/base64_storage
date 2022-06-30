#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Date {
private:
    const unsigned int MINYEAR = 0;
    const unsigned int MAXYEAR = 9999;
public:
    unsigned int year = 1970;
    unsigned int month = 1;
    unsigned int day = 1;

    string str();
    static Date now();
    Date(unsigned int y, unsigned int m, unsigned int d);
    Date();
};

ostream& operator<<(ostream& out, Date d);
Date operator + (Date d1, Date d2);

#endif // !DATE_H
