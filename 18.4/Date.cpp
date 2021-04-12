#include "DATE.h"
DATE::DATE(void) :TRIAD() {}
DATE::~DATE(void) {}
DATE::DATE(int Day, int Month, int Year) : TRIAD(Day, Month, Year) {}
DATE::DATE(const DATE& D) {
    first = D.first;
    second = D.second;
    third = D.third;
}

DATE DATE::operator++(int)
{
    first++;
    second++;
    third++;
    int temp = first + second * 30 + third * 365;
    DATE t(first, second, third);
    third = temp / 365;
    temp = temp % 365;
    second = temp / 30;
    temp = temp % 30;
    first = temp;
    return t;
}

DATE DATE::operator+(int days) {
    int temp = first + second * 30 + third * 365 + days;

    DATE t(first, second, third);
    third = temp / 365;
    temp = temp % 365;
    second = temp / 30;
    temp = temp % 30;
    first = temp;
    return t;
}

void DATE::year(int Year) {
    first = Year;
}

void DATE::month(int Month) {
    second = Month;
}

void DATE::day(int Day) {
    third = Day;
}

ostream& operator<<(ostream& out, const DATE& t)
{
    out << endl << "Day: " << t.first;
    out << endl << "Mount: " << t.second;
    out << endl << "Year: " << t.third;
    out << endl;
    return out;
}