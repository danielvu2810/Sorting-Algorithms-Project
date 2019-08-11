#include "sorting.h"
#include "helper.h"
#include "random_generation.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

void insertion_sort(std::vector<int>& nums)
{
	if (nums.size() >= 2)
	{
		int temp, j;
		for (int i = 1; i < nums.size(); i++)
		{
			temp = nums[i];
			j = i - 1;
			for (; j >= 0 && nums[j] > temp; j--)
			{
				nums[j + 1] = nums[j];

			}

			nums[j + 1] = temp;
		}
	}
}
