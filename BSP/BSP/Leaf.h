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
	int		x2;
	int		y2;

	pair<int, int>* path;

	int		topLineS_X;
	int		topLineS_Y;

	int		topLineB_X;
	int		topLineB_Y;

	int		botLineS_X;
	int		botLineS_Y;

	int		botLineB_X;
	int		botLineB_Y;

	Leaf*	leftChild;
	Leaf*	rightChild;

	bool isRoom;

	Leaf(int x, int y, int x2, int y2) : x(x), y(y), x2(x2), y2(y2)
	{
		leftChild	= NULL;
		rightChild	= NULL;

		topLineS_X = (x <= x2) ? x : x2;
		topLineS_Y = (y <= y2) ? y : y2;

		topLineB_X = (x <= x2) ? x2 : x;
		topLineB_Y = (y <= y2) ? y : y2;

		botLineS_X = (x <= x2) ? x : x2;
		botLineS_Y = (y <= y2) ? y2 : y;
		
		botLineB_X = (x <= x2) ? x2 : x;
		botLineB_Y = (y <= y2) ? y2 : y;

		path = NULL;

		isRoom = false;
	};
	~Leaf();

	void CreateRoom();
	pair<int, int>* GetRoom();

	void CreateHall(pair<int, int>* leftChild, pair<int, int>* rightChild);

	bool Split();

	void PrintLeaf();
	void GotoXY(int x, int y, const char c);

	void RootPrint();
};

//class Leaf
//{
//private:
//	const int MIN_LEAF_SIZE = 6;
//public:
//	int		x;
//	int		y;
//	int		x2;
//	int		y2;
//
//	Leaf*	leftChild = NULL;
//	Leaf*	rightChild = NULL;
//
//	Leaf(int x, int y, int x2, int y2) : x(x), y(y), x2(x2), y2(y2)
//	{};
//	~Leaf();
//
//	bool split();
//	void createRooms();
//
//	void printLeaf();
//	void gotoxy(int x, int y, const char c);
//};

