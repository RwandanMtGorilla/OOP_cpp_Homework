// time.cpp
#include "time.h"
#include <iostream>
#include <iomanip>

using std::cout;

Time::Time(int h, int m, int s) {
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    if(h >= 0 && h < 24) {
        hour = h;
    } else {
        hour = 0;
    }
}

int Time::getHour() {
    return hour;
}

void Time::setMinute(int m) {
    if(m >= 0 && m < 60) {
        minute = m;
    } else {
        minute = 0;
    }
}

int Time::getMinute() {
    return minute;
}

void Time::setSecond(int s) {
    if(s >= 0 && s < 60) {
        second = s;
    } else {
        second = 0;
    }
}

int Time::getSecond() {
    return second;
}

void Time::printStandard() {
    cout << std::setfill('0') 
         << std::setw(2) << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
         << std::setw(2) << getMinute() << ":"
         << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

void Time::tick() {
    if(++second > 59) {
        second = 0;
        if(++minute > 59) {
            minute = 0;
            if(++hour > 23) {
                hour = 0;
            }
        }
    }
}
