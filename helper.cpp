#include "helper.h"
#include "timing.h"


int findMin(int a, int b)
{
	return (a < b) ? a : b;
}

int findMax(int a, int b)
{
	return (a > b) ? a : b;
}

string checkSorted(vector<int> uniform_v)
{
	if (is_sorted(uniform_v.begin(), uniform_v.end()))
		return "sorted";
		
	else return "unsorted";
}

void createVectors(vector<vector<int>>& vectors,int size)
{
	vector<int> v;
	vector<int> randomsize;

	mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
	uniform_int_distribution<int> ui;
	for (int i = 10; i < size; i *= 10)
	{
		ui = get_uniform_int_generator(i,i*10);
		randomsize.push_back(ui(mt));
	}
	
	for (int i = 0; i < randomsize.size(); i++)
	{

		for (int j = 1; j <= randomsize[i]; j++)
		{
			v.push_back(j);
		}
		vectors.push_back(v);
		v.clear();
	}
}

//permutation == true if uniformly distributed else false if almost-sorted
string shuffle_by_Selection(vector<vector<int>>& vectors, bool permutation)
{
	if (permutation)
	{
		for (int i = 0; i < vectors.size(); i++)
			uniform_shuffle_vector(vectors[i]);
		return "uniformly distributed";
	}
	else
	{
		for (int i = 0; i < vectors.size(); i++)
			almost_shuffle_vector(vectors[i]);
		return "almost-sorted";
	}
}

void sort_and_time_All(string filename, vector<vector<int>> vectors, vector<int> gaps1, vector<int> gaps2, vector<int> temps1, vector<int> temps2, vector<int> reps1, vector<int> reps2,bool permutation)
{
	timing_for_bubble_sort(filename, vectors, permutation);
	timing_for_insertion_sort(filename, vectors, permutation);
	timing_for_spin_the_bottle_sort(filename, vectors, permutation);
	timing_for_shell_sort1(filename, vectors, gaps1, permutation);
	timing_for_shell_sort2(filename, vectors, gaps2, permutation);
	timing_for_annealing_sort1(filename, vectors, temps1, reps1, permutation);
	timing_for_annealing_sort2(filename, vectors, temps2, reps2, permutation);
}

void printVectors(vector < vector<int>> vectors)
{
	////////////////////////////
	for (int i = 0; i < vectors.size(); i++)
	{
		for (int j = 0; j < vectors[i].size(); j++)
			cout << vectors[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
	////////////////////////////
}