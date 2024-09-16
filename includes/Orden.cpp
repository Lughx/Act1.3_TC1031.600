#include "Orden.h"
#include <vector>
#include "Line.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Orden::quickSort(std::vector<Line>& vec, int low, int high) {
    if (low < high) {
        // pi is partitioning index, vec[pi] is now at right place
        int pi = partition(vec, low, high);

        // Separately sort elements before partition and after partition
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int Orden::partition(std::vector<Line>& vec, int low, int high) {
    int pivot = vec[high].getTotalSec(); // pivot based on the key
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element's key is smaller than or equal to pivot
        if (vec[j].getTotalSec() <= pivot) {
            i++;    // increment index of smaller element
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return (i + 1);
}