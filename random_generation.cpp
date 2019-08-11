#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "random_generation.h"

mt19937 get_mersenne_twister_generator_with_current_time_seed()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	return mt19937(seed);
}

uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub)
{
	return uniform_int_distribution<int>(lb, ub);
}

void uniform_shuffle_vector(vector<int>& nums)
{
	if (nums.size() >= 2)
	{
		mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

		uniform_int_distribution<int> ui;

		int r, temp;

		for (int i = 0; i < nums.size() - 2; i++)
		{
			ui = get_uniform_int_generator(i, nums.size() - 1);
			r = ui(mt);
			temp = nums[i];
			nums[i] = nums[r];
			nums[r] = temp;
		}
	}
}

void almost_shuffle_vector(vector<int>& nums)
{
	if (nums.size() >= 2)
	{
		mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

		uniform_int_distribution<int> ui;

		double logn = log(nums.size());
		int ilogn = (int)logn;

		if (ilogn <= 0) ilogn = 1;

		int pairnum = ilogn * 2;

		int j, k,temp;
		for (int i = 0; i < pairnum; i++)
		{
			ui = get_uniform_int_generator(0, nums.size() - 1);
			j = ui(mt);
			k = ui(mt);
			if (j == k) i--;
			else
			{
				temp = nums[j];
				nums[j] = nums[k];
				nums[k] = temp;
			}
		}
	}
}

