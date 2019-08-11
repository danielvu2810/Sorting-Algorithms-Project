#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <string>
#include <ctime>
#include "sorting.h"
#include "random_generation.h"
#include "sequence_generation.h"
#include "helper.h"
#include "timing.h"

#define MAX_VECTORSIZE 10000
#define FILENAME "timing.csv"

using namespace std;

int main()
{
		vector<vector<int>> vectors;
		createVectors(vectors, MAX_VECTORSIZE);

		vector<int> temps1,temps2,reps1,reps2,gaps1,gaps2;

		gapGeneration1(gaps1, MAX_VECTORSIZE);
		gapGeneration2(gaps2, MAX_VECTORSIZE);
		temprepGeneration(temps1, reps1, MAX_VECTORSIZE);
		temprepGeneration(temps2, reps2, MAX_VECTORSIZE);

		info time;

		createCSVFile(FILENAME);

		//permutation == true if uniformly distributed else false if almost-sorted
		sort_and_time_All(FILENAME, vectors, gaps1, gaps2, temps1, temps2, reps1, reps2, true);
		sort_and_time_All(FILENAME, vectors, gaps1, gaps2, temps1, temps2, reps1, reps2, false);
			   		 
		return 0;
}