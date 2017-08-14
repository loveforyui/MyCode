#include "MRandom.h"



MRandom::MRandom()
{
}


MRandom::~MRandom()
{
}

int MRandom::getRandomNumber(int min, int max)
{
	//< 1�ܰ�. �õ� ����
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2�ܰ�. ���� ���� ( ���� )
	uniform_int_distribution<int> range(min, max);

	//< 3�ܰ�. �� ����
	return range(rnd);
}
