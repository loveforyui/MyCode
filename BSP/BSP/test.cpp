#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>

using namespace std;


void gotoxy(int x, int y);

void main()
{
	const int MAX_X_SIZE = 10;
	const int MAX_Y_SIZE = 10;

	vector<pair<int, int>> posVector;

	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;

	srand((unsigned)time(NULL));

	x = rand() % 10;
	y = rand() % 10;

	w = rand() % 10;
	h = rand() % 10;

	posVector.push_back(pair<int, int>((x < w) ? x : w, (y < h) ? y : h));	//TopLine S
	posVector.push_back(pair<int, int>((x < w) ? w : x, (y < h) ? y : h));	//TopLine B
	posVector.push_back(pair<int, int>((x < w) ? x : w, (y < h) ? h : y));	//BotLine S
	posVector.push_back(pair<int, int>((x < w) ? w : x, (y < h) ? h : y));	//BotLine B

	cout << endl;

	//cout << posVector[0].first << ", " << posVector[1].first - posVector[0].first << endl;
	//TopLineDrawing	
	for (int i = posVector[0].first; i < posVector[1].first - posVector[0].first; ++i)
	{
		gotoxy(i, posVector[0].second);
	}
	//BotLineDrawing
	for (int i = posVector[0].first; i < posVector[1].first - posVector[0].first; ++i)
	{
		gotoxy(i, posVector[2].second);
	}
	//LeftLineDrawing
	for (int i = posVector[2].second; i < posVector[3].second - posVector[2].second; ++i)
	{
		gotoxy(posVector[0].first, i);
	}
	//RightLineDraing
	for (int i = posVector[2].second; i < posVector[3].second - posVector[2].second; ++i)
	{
		gotoxy(posVector[1].first, i);
	}

	gotoxy(0, 12);

	cout << " x: " << x << " y: " << y << " w: " << w << " h: " << h << endl;

	for (vector<pair<int, int>>::size_type i = 0; i < posVector.size(); ++i)
	{
		cout << "i= " << i << " x, y :" << posVector[i].first << ", " << posVector[i].second << endl;
	}

	system("pause");
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	cout << 'x';
}
