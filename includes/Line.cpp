//
// Created by lughx on 9/15/24.
//

#include "Line.h"
#include "Utils.h"
#include <iostream>
#include <ostream>
#include <vector>

Line::Line() {
    month = 0;
    day = 0;
    hour = "";
    ip = "";
    message = "";
}

Line::Line(int _month, string _monthStr, int _day, string _hour, string _ip, string _message) {
    month = _month;
    monthStr = _monthStr;
    day = _day;
    hour = _hour;
    Utils utils;
    vector<string> tokens = utils.SplitString(_hour, ":");

    struct tm _datetime;
    _datetime.tm_year = 1901 - 1900;
    _datetime.tm_mon = _month - 1;
    _datetime.tm_mday = _day;
    _datetime.tm_hour = stoi(tokens[0]);
    _datetime.tm_min = stoi(tokens[1]);
    _datetime.tm_sec = stoi(tokens[2]);
    _datetime.tm_isdst = -1;

    datetime = _datetime;

    ip = _ip;
    message = _message;
}

void Line::test(time_t date2) {
    time_t date1 = mktime(&datetime);
    //time(&timestamp);

    cout << difftime(date1, date2);
}

time_t Line::getTotalSec() {
    time_t tim = mktime(&datetime);
    tm afterDatetime;
    afterDatetime.tm_year = 1903 - 1900;
    afterDatetime.tm_mon = 2;
    afterDatetime.tm_mday = 1;
    afterDatetime.tm_hour = 1;
    afterDatetime.tm_min = 1;
    afterDatetime.tm_sec = 1;
    afterDatetime.tm_isdst = -1;
    time_t after = mktime(&afterDatetime);

    return difftime(tim, after);
}

string Line::print() {
    return  monthStr + " " + to_string(day) + " " + hour + " " + ip + " " + message + "\n";
}