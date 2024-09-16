#pragma once
#include <vector>
#include <string>
#include "Line.h"
using namespace std;

class Orden
{
public:
	static void quickSort(vector<Line>&, int , int );
private:
	//static void swap(int*, int*);
	static int partition(vector<Line>&, int, int);
};

