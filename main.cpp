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

int main() {
    Utils utils;
    cout << "Cargando datos... " << endl;
    vector<Line> lines = utils.Read_file("/home/lughx/CLionProjects/actividad1.3/bitacora.txt");
    cout << "Ordenando los datos... " << endl;
    Orden orden;
    orden.quickSort(lines, 0, lines.size() - 1);

    cout << "Ingresa la fecha de inicio, con hora" << endl;
    time_t init = utils.Ask_and_get_tm();
    cout << "Ingresa la fecha final, con hora" << endl;
    time_t final = utils.Ask_and_get_tm();

    if (init > final) {
        cout << "La fecha final no puede ser mas chica que la inicial" << endl;
        return 0;
    }

    utils.Create_file(lines, init, final);



    return 0;
}
