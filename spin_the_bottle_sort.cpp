#include "helper.h"
#include "random_generation.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>


void spin_the_bottle_sort(std::vector<int>& nums)
{
	if (nums.size() >= 2)
	{
		mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

		uniform_int_distribution<int> ui;
		int r;//ui(mt)
		int temp = 0;

		while (!is_sorted(nums.begin(), nums.end()))
		{
			for (int i = 0; i < nums.size(); i++)
			{
				ui = get_uniform_int_generator(0, nums.size() - 1);
				r = ui(mt);

				if ((i<r && nums[i]>nums[r]) || (i > r && nums[i] < nums[r]))
				{
					temp = nums[i];
					nums[i] = nums[r];
					nums[r] = temp;
				}
			}
		}
	}
}