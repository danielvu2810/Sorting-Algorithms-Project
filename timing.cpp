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

void createCSVFile(string filename)
{
	ofstream f;
	f.open(filename, ios::trunc);
	cout << "Sorting Method\tPermutation Type\tSize\tSeconds\tStatus\n";
	f << "Sorting Method,Permutation Type,Size,Seconds,Status\n";
	f.close();
}

void add_time_to_File(string filename, info t)
{
	ofstream f;
	f.open(filename, ios::app);
	cout << t.funcname << "\t" << t.permutation << "\t" << t.size << "\t" << t.seconds << "\t" << t.status << "\n";
	f << t.funcname << "," << t.permutation << "," << t.size << "," << t.seconds << "," << t.status << "\n";
	f.close();
}

void timing_for_bubble_sort(string filename, std::vector<vector<int>> vectors, bool permutation)
{
	info t;

	string spermutation=shuffle_by_Selection(vectors, permutation);


	for (int i = 0; i < vectors.size(); i++)
	{
		clock_t c_start = clock();
		bubble_sort(vectors[i]);
		clock_t c_end = clock();

		t.funcname = "Bubble_sort";
		t.permutation = spermutation;
		t.size = vectors[i].size();
		t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC/1000) / 1000;
		t.status = checkSorted(vectors[i]);

		add_time_to_File(filename, t);
	}
}

void timing_for_insertion_sort(string filename, std::vector<vector<int>> vectors, bool permutation)
{
	info t;
	
	string spermutation = shuffle_by_Selection(vectors, permutation);

	for (int i = 0; i < vectors.size(); i++)
	{
		clock_t c_start = clock();
		insertion_sort(vectors[i]);
		clock_t c_end = clock();

		t.funcname = "Insertion_sort";
		t.permutation = spermutation;
		t.size = vectors[i].size();
		t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC / 1000) / 1000;
		t.status = checkSorted(vectors[i]);

		add_time_to_File(filename, t);
	}
}

void timing_for_spin_the_bottle_sort(string filename, std::vector<vector<int>> vectors, bool permutation)
{
	info t;

	string spermutation = shuffle_by_Selection(vectors, permutation);

	for (int i = 0; i < vectors.size(); i++)
	{
		clock_t c_start = clock();
		spin_the_bottle_sort(vectors[i]);
		clock_t c_end = clock();

		t.funcname = "Spin_the_bottle_sort";
		t.permutation = spermutation;
		t.size = vectors[i].size();
		t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC / 1000) / 1000;
		t.status = checkSorted(vectors[i]);

		add_time_to_File(filename, t);
	}
}
void timing_for_shell_sort1(string filename, std::vector<vector<int>> vectors, const std::vector<int> gaps, bool permutation)
{
	info t;

	string spermutation = shuffle_by_Selection(vectors, permutation);

	for (int i = 0; i < vectors.size(); i++)
	{
		clock_t c_start = clock();
		shell_sort(vectors[i], gaps);
		clock_t c_end = clock();

		t.funcname = "Shell_sort (1st gap sequence)";
		t.permutation = spermutation;
		t.size = vectors[i].size();
		t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC / 1000) / 1000;
		t.status = checkSorted(vectors[i]);

		add_time_to_File(filename, t);
	}


}

void timing_for_shell_sort2(string filename, std::vector<vector<int>> vectors, const std::vector<int> gaps, bool permutation)
{
	info t;

	string spermutation = shuffle_by_Selection(vectors, permutation);


	for (int i = 0; i < vectors.size(); i++)
	{
		clock_t c_start = clock();
		shell_sort(vectors[i], gaps);
		clock_t c_end = clock();

		t.funcname = "Shell_sort (2nd gap sequence)";
		t.permutation = spermutation;
		t.size = vectors[i].size();
		t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC / 1000) / 1000;
		t.status = checkSorted(vectors[i]);

		add_time_to_File(filename, t);
	}

}

void timing_for_annealing_sort1(string filename, std::vector<vector<int>> vectors, const std::vector<int> temps, const std::vector<int> reps, bool permutation)
{
	info t;

	string spermutation = shuffle_by_Selection(vectors, permutation);

	for (int i = 0; i < vectors.size(); i++)
	{
	clock_t c_start = clock();
	annealing_sort(vectors[i], temps, reps);
	clock_t c_end = clock();

	t.funcname = "Annealing_sort (1st temp & rep sequence)";
	t.permutation = spermutation;
	t.size = vectors[i].size();
	t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC / 1000) / 1000;
	t.status = checkSorted(vectors[i]);

	add_time_to_File(filename, t);
	}
}

void timing_for_annealing_sort2(string filename, std::vector<vector<int>> vectors, const std::vector<int> temps, const std::vector<int> reps, bool permutation)
{
	info t;
	
	string spermutation=shuffle_by_Selection(vectors, permutation);

	for (int i = 0; i < vectors.size(); i++)
	{
		clock_t c_start = clock();
		annealing_sort(vectors[i], temps, reps);
		clock_t c_end = clock();

		t.funcname = "Annealing_sort (2nd temp & rep sequence)";
		t.permutation = spermutation;
		t.size = vectors[i].size();
		t.seconds = (double)(c_end - c_start) / (CLOCKS_PER_SEC / 1000)/1000;
		t.status = checkSorted(vectors[i]);

		add_time_to_File(filename, t);
	}

}

