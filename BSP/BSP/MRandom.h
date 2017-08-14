#pragma once
#include <iostream>
#include <random>

using namespace std;

class MRandom
{
public:
	MRandom();
	~MRandom();

	int getRandomNumber(int min, int max);
};