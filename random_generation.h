#include <iostream>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

mt19937 get_mersenne_twister_generator_with_current_time_seed();
uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub);

void uniform_shuffle_vector(vector<int>& nums);

void almost_shuffle_vector(vector<int>& nums);