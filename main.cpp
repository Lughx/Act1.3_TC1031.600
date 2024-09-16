#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <Line.h>
#include <Orden.h>
#include <ctime>
#include <Utils.h>

using namespace std;

vector<Line> Read_file(string file_name) {
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

time_t Ask_and_get_tm() {
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

int main() {
    cout << "Cargando datos... " << endl;
    vector<Line> lines = Read_file("/home/lughx/CLionProjects/actividad1.3/bitacora.txt");

    cout << "Ordenando los datos... " << endl;
    Orden orden;
    orden.quickSort(lines, 0, lines.size() - 1);

    cout << "Ingresa la fecha de inicio, con hora" << endl;
    time_t init = Ask_and_get_tm();
    cout << "Ingresa la fecha final, con hora" << endl;
    time_t final = Ask_and_get_tm();

    if (init > final) {
        cout << "La fecha final no puede ser mas chica que la inicial" << endl;
        return 0;
    }

    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].getTotalSec() > init && lines[i].getTotalSec() < final) {
            lines[i].print();
        }
    }

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
    }

    return 0;
}
