#include "MRandom.h"



MRandom::MRandom()
{
}


MRandom::~MRandom()
{
}

int MRandom::getRandomNumber(int min, int max)
{
	//< 1단계. 시드 설정
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> range(min, max);

	//< 3단계. 값 추출
	return range(rnd);
}
