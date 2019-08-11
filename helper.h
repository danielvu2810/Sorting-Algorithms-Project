#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "sorting.h"
#include <string>
#include "random_generation.h"

int findMin(int a, int b);
int findMax(int a, int b);
string checkSorted(vector<int> uniform_v);
void createVectors(vector<vector<int>>& vectors,int size);
string shuffle_by_Selection(vector<vector<int>>& vectors, bool permutation);
void printVectors(vector < vector<int>> vectors);
void sort_and_time_All(string filename, vector<vector<int>> vectors, vector<int> gaps1, vector<int> gaps2, vector<int> temps1, vector<int> temps2, vector<int> reps1, vector<int> reps2, bool permutation);