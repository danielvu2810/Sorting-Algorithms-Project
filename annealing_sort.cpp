#include "sorting.h"
#include "helper.h"
#include "random_generation.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>


void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps)
{
	if (nums.size() >= 2)
	{
		mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

		uniform_int_distribution<int> ui;
		int r;//ui(mt)
		int temp;

		for (int j = 0; j < temps.size(); j++)
		{
			for (int i = 0; i < nums.size() - 1; i++)
			{
				for (int k = 1; k <= reps[j]; k++)
				{
					ui = get_uniform_int_generator(i + 1, findMin(nums.size() - 1, i + 1 + temps[j]));
					r = ui(mt);

					if (nums[i] > nums[r])
					{
						temp = nums[r];
						nums[r] = nums[i];
						nums[i] = temp;
					}

				}
			}

			for (int i = nums.size() - 1; i >= 1; i--)
			{
				for (int k = 1; k <= reps[j]; k++)
				{
					ui = get_uniform_int_generator(findMax(0, i - temps[j]), i);
					r = ui(mt);

					if (nums[r] > nums[i])
					{
						temp = nums[r];
						nums[r] = nums[i];
						nums[i] = temp;
					}


				}

			}

		}
	}
}

