//
// Created by lughx on 9/15/24.
//

#include "Utils.h"
#include "Line.h"
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

vector<Line> Utils::Read_file(string file_name) {
    ifstream inputFile(file_name);

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return {Line()};
    }

    vector<Line> lines;
    string line;

    Utils utils;

    while (getline(inputFile, line)) {
        string s;
        stringstream ss(line);
        int counter = 0;

        int day = 0;
        int month = 0;
        string monthStr = "";
        string hour = "";
        string ip = "";
        string comment = "";

        while (getline(ss, s, ' ')) {
            switch (counter) {
                case 0:
                    month = utils.From_string_to_number(s);
                monthStr = s;
                break;
                case 1:
                    day = stoi(s);
                break;
                case 2:
                    hour = s;
                break;
                case 3:
                    ip = s;
                break;
                default:
                    comment += s + " ";
            }
            counter++;
        }
        lines.push_back(Line(month, monthStr, day, hour, ip, comment));
    }
    inputFile.close();

    return lines;
}

time_t Utils::Ask_and_get_tm() {
    int day;
    int month;
    string hourFormat;
    Utils utils;

    cout << "Ingresa el dia: " << endl;
    cin >> day;
    cout << "Ingresa el mes: " << endl;
    cin >> month;
    cout << "Ingresa la hora con el siguiente formato(hora:minuto:segundo): " << endl;
    cin >> hourFormat;

    vector<string> divided = utils.SplitString(hourFormat, ":");

    tm datetime;
    datetime.tm_year = 1901 - 1900;
    datetime.tm_mon = month - 1;
    datetime.tm_mday = day;
    datetime.tm_hour = stoi(divided[0]);
    datetime.tm_min = stoi(divided[1]);
    datetime.tm_sec = stoi(divided[2]);

    return (utils.Get_time_difference(mktime(&datetime)));
}

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

void Utils::Create_file(vector<Line> lines, time_t init, time_t final) {
    ofstream outputFile("resultado.txt");

    if (outputFile.is_open()) {
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i].getTotalSec() > init && lines[i].getTotalSec() < final) {
                outputFile << lines[i].print();
            } else if (lines[i].getTotalSec() > final) break;
        }

        outputFile.close();

        std::cout << "Se ha creado el archivo con el resultado" << std::endl;
    } else {
        std::cout << "Hubo un fallo al crear el archivo" << std::endl;
    }}
