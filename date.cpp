#include "Date.h"
    
string Date::str() {
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
}

    Date Date::now() {
        SYSTEMTIME t;
        GetLocalTime(&t);
        return Date(t.wYear, t.wMonth, t.wDay);
    }

    Date::Date(unsigned int y, unsigned int m, unsigned int d) {
        if (y > MINYEAR && y < MAXYEAR)
            year = y;
        else
            year = MINYEAR;
        if (m > 12)
            month = 12;
        else
            month = m;
        if (d > 31)
            day = 31;
        else
            day = d;
    }

    Date::Date() {
        this->year = Date::now().year;
        this->month = Date::now().month;
        this->day = Date::now().day;
    }


ostream& operator<<(ostream& out, Date d)
{
    out << to_string(d.year) + "-" + to_string(d.month) + "-" + to_string(d.day) << endl;
    return out;
}

Date operator + (Date d1, Date d2) {
    unsigned int new_year = d1.year + d2.year;
    unsigned int new_month = d1.month + d2.month;
    if (new_month > 12) {
        new_month -= 12;
        new_year++;
    }
    unsigned int new_day = d1.day + d2.day;
    if (new_day > 31) {
        new_day -= 31;
        new_month++;
    }
    return Date(new_year, new_month, new_day);
}
