#include "sorting.h"
#include "helper.h"
#include "random_generation.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

void bubble_sort(std::vector<int>& nums)
{
	if (nums.size() >= 2)
	{
		int temp = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = 0; j < nums.size() - 1 - i; j++)
			{
				if (nums[j] > nums[j + 1])
				{
					temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
		}
	}
}