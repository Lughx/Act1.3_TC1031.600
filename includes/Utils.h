//
// Created by lughx on 9/15/24.
//

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
using namespace std;
class Utils {
private:
public:
    vector<string> SplitString(string, string);
    time_t Get_time_difference(time_t date);
    int From_string_to_number(string);
};



#endif //UTILS_H
