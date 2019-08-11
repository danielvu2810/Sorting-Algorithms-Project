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

struct info
{
	int size;
	double seconds;
	string funcname;
	string permutation;
	string status;
};

void createCSVFile(string filename);
void add_time_to_File(string filename, info t);

void timing_for_bubble_sort(string filename, std::vector<vector<int>> vectors, bool permutation);
void timing_for_insertion_sort(string filename, std::vector<vector<int>> vectors, bool permutation);
void timing_for_spin_the_bottle_sort(string filename, std::vector<vector<int>> vectors, bool permutation);
void timing_for_shell_sort1(string filename, std::vector<vector<int>> vectors, const std::vector<int> gaps, bool permutation);
void timing_for_shell_sort2(string filename, std::vector<vector<int>> vectors, const std::vector<int> gaps, bool permutation);
void timing_for_annealing_sort1(string filename, std::vector<vector<int>> vectors, const std::vector<int> temps, const std::vector<int> reps, bool permutation);
void timing_for_annealing_sort2(string filename, std::vector<vector<int>> vectors, const std::vector<int> temps, const std::vector<int> reps, bool permutation);
