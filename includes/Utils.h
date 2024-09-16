//
// Created by lughx on 9/15/24.
//

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <Line.h>
using namespace std;

class Utils {
private:
public:
    vector<Line> Read_file(string);
    time_t Ask_and_get_tm();
    vector<string> SplitString(string, string);
    time_t Get_time_difference(time_t);
    int From_string_to_number(string);
    void Create_file(vector<Line>, time_t, time_t);
};



#endif //UTILS_H
