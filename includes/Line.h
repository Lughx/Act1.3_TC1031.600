#ifndef LINE_H
#define LINE_H

#include <string>
#include <ctime>

using namespace std;

class Line {
private:
    int month;
    int day;
    string monthStr;
    string hour;
    string ip;
    string message;
    tm datetime;
public:
    Line();
    Line(int month, string monthStr, int day, string hour, string ip, string message);
    int getMonth();
    int getDay();
    time_t getTotalSec();
    void test(time_t);
    string print();
};



#endif //LINE_H