#include "sequence_generation.h"
#include "helper.h"

void gapGeneration1(std::vector<int>& gaps, int size)
{
	gaps.clear();

	int k = 1;
	int gap = 1;

	if (size >= 2)
	{
		for (int i = 0; gap <= size; i++)
		{
			gaps.push_back(gap);
			gap = (int)(pow(4, i + 1) + 3 * pow(2, i));
		}
	}
	
}

void gapGeneration2(std::vector<int>& gaps, int size)
{
	gaps.clear();

	int k = 1;
	int gap = 1;

	if (size >= 2)
	{
		for (int i = 0; gap <= size; i++)
		{
			gaps.push_back(gap);
			gap = (int)(8 * pow(2, i) - 6 * pow(2, (int)((i + 1) / 2)) + 1);
		}	
	}
}

void temprepGeneration(std::vector<int>& temps, std::vector<int>& reps, int size)
{
	temps.clear();
	reps.clear();
	int firsttemp = 2 * size;
	int phase1temp, phase2temp, phase3temp, c, r;

	double logn = log(size) / log(10);
	double logn6 = pow(log(size) / log(10), 6);

	int ilogn6 = (int)logn6;
	int ilogn = (int) logn;

	if (ilogn <= 0) logn = 1;
	if (ilogn6 <= 0) ilogn6 = 1;

	mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

	uniform_int_distribution<int> ui;

	//phase1

	if (ilogn6 <= firsttemp)
	{
		ui = get_uniform_int_generator(1, firsttemp / ilogn6);

		phase1temp = ui(mt) * ilogn6;
	}
	else phase1temp = firsttemp;

	temps.push_back(firsttemp);
	int divisor = 1;
	for (int i = 1; temps[i - 1] >= phase1temp; i++)
	{
		if (i % 2 == 0) divisor *= 2;
		temps.push_back(firsttemp / divisor);
	}

	ui = get_uniform_int_generator(1, phase1temp);
	r = ui(mt);

	for (int i = 0; i < temps.size(); i++)
		reps.push_back(r);

	//phase2
	if (phase1temp >= logn)
	{
		ui = get_uniform_int_generator(1, phase1temp / logn);

		phase2temp = ui(mt) * logn;
	}
	else phase2temp = phase1temp;

	for (int i = temps.size() - 1; temps[i] >= phase2temp; i++)
	{
		temps.push_back(temps[i] / 2);
	}

	ui = get_uniform_int_generator(1, phase2temp);
	r = ui(mt);

	int diff = temps.size() - reps.size();

	for (int i = 0; i < diff; i++)
		reps.push_back(r);

	//phase3
	for (int i = 0; i < ilogn; i++)
	{
		temps.push_back(1);
		reps.push_back(1);
	}
}

