#include <iostream>

struct Time {
    unsigned int milliseconds : 10; // 10 bits for milliseconds (0-999)
    unsigned int seconds : 6;       // 6 bits for seconds (0-59)
    unsigned int minutes : 6;       // 6 bits for minutes (0-59)
    unsigned int hours : 5;         // 5 bits for hours (0-23)
    unsigned int day : 5;           // 5 bits for day (1-31)
    unsigned int month : 4;         // 4 bits for month (1-12)
    unsigned int year : 12;         // 12 bits for year (0-4095)
};

int main() {
    Time t;

    
    t.year = 2022;
    t.month = 12;
    t.day = 31;
    t.hours = 23;
    t.minutes = 59;
    t.seconds = 59;
    t.milliseconds = 999;

    
    std::cout << "Date and time: ";
    std::cout << t.year << "-" << t.month << "-" << t.day << " ";
    std::cout << t.hours << ":" << t.minutes << ":" << t.seconds << "." << t.milliseconds << std::endl;

    return 0;
}
