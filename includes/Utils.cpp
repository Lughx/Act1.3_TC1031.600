//
// Created by lughx on 9/15/24.
//

#include "Utils.h"
#include <vector>
#include <string>
#include <ctime>
using namespace std;

time_t Utils::Get_time_difference(time_t date) {
    tm afterDatetime;
    afterDatetime.tm_year = 1903 - 1900;
    afterDatetime.tm_mon = 2;
    afterDatetime.tm_mday = 1;
    afterDatetime.tm_hour = 1;
    afterDatetime.tm_min = 1;
    afterDatetime.tm_sec = 1;
    afterDatetime.tm_isdst = -1;
    time_t after = mktime(&afterDatetime);

    return difftime(date, after);
}

int Utils::From_string_to_number(string month) {
    if (month == "Jan") return 1;
    if (month == "Feb") return 2;
    if (month == "Mar") return 3;
    if (month == "Apr") return 4;
    if (month == "May") return 5;
    if (month == "Jun") return 6;
    if (month == "Jul") return 7;
    if (month == "Aug") return 8;
    if (month == "Sep") return 9;
    if (month == "Oct") return 10;
    if (month == "Nov") return 11;
    if (month == "Dec") return 12;

    return 0;
}

vector<string> Utils::SplitString(string s, string del = " ")
{
    vector<string> tokens;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tokens.push_back(s.substr(start, end - start));
    } while (end != -1);

    return tokens;
}
