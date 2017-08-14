#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include "MRandom.h"

using namespace std;

class Leaf
{
private:
	const int MIN_LEAF_SIZE = 6;
public:
	int		x;
	int		y;
	int		width;
	int		height;

	Leaf*	leftChild = NULL;
	Leaf*	rightChild = NULL;

	Leaf(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
	{};
	~Leaf();

	bool split();
	void createRooms();

	void printLeaf();
	void gotoxy(int x, int y, const char c);
};

