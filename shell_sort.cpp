#include "helper.h"
#include "random_generation.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps)
{
	if (nums.size() >= 2)
	{
		int temp, gap, j;

		for (int temp_index = gaps.size() - 1; temp_index >= 0; temp_index--)
		{
			gap = gaps[temp_index];
			for (int i = gap; i < nums.size(); i++)
			{
				temp = nums[i];
				j = i;

				while (j >= gap && temp < nums[j - gap])
				{
					nums[j] = nums[j - gap];
					j -= gap;
				}

				nums[j] = temp;
			}
		}
	}
}