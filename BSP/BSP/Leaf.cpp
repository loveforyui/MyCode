#include "Leaf.h"


void Leaf::PrintLeaf()
{
	if (isRoom)
	{
		//TopLineDrawing
		for (int i = this->topLineS_X; i < this->topLineB_X; ++i)
		{
			GotoXY(i, this->topLineS_Y, 'X');
		}
		//BottomLineDrawing
		for (int in = this->topLineS_X; in < this->topLineB_X; ++in)
		{
			GotoXY(in, this->botLineS_Y, 'X');
		}
		//LeftLineDrawing
		for (int ik = this->topLineS_Y; ik < this->botLineS_Y; ++ik)
		{
			GotoXY(this->topLineS_X, ik, 'X');
		}
		//RightLineDrawing
		for (int ig = this->topLineS_Y; ig <= this->botLineS_Y; ++ig)
		{
			GotoXY(this->topLineB_X, ig, 'X');
		}

		GotoXY(0, 31, ' ');
		cout << "x: " << x << " y: " << y << " x2: " << x2 << " y2: " << y2 << endl;
	}

	//system("pause > NULL");
}

void Leaf::GotoXY(int x, int y, const char c)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	cout << c;
}

void Leaf::RootPrint()
{
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			GotoXY(j, i, 'X');
		}
	}
}

Leaf::~Leaf()
{
}

void Leaf::CreateRoom()
{
	const int MIN_ROOM_SIZE = 4;

	MRandom m;

	if (leftChild != NULL || rightChild != NULL)
	{
		if (leftChild != NULL)
		{
			leftChild->CreateRoom();
		}
		if (rightChild != NULL)
		{
			rightChild->CreateRoom();
		}
		if (leftChild != NULL && rightChild != NULL)
		{
			CreateHall(leftChild->GetRoom(), rightChild->GetRoom());
		}
	}
	else
	{
		topLineS_X = m.getRandomNumber(x + 1, x2 - 1 - MIN_ROOM_SIZE);
		topLineS_Y = m.getRandomNumber(y + 1, y2 - 1 - MIN_ROOM_SIZE);

		botLineB_X = m.getRandomNumber(topLineS_X + MIN_ROOM_SIZE, x2 - 1);
		botLineB_Y = m.getRandomNumber(topLineS_Y + MIN_ROOM_SIZE, y2 - 1);

		topLineB_X = botLineB_X;
		topLineB_Y = topLineS_Y;

		botLineS_X = topLineS_X;
		botLineS_Y = botLineB_Y;

		path = new pair<int, int>(m.getRandomNumber(topLineS_X + 1, topLineB_X - 1), m.getRandomNumber(topLineS_Y + 1, botLineB_Y - 1));

		isRoom = true;
		PrintLeaf();
	}
}

pair<int, int>* Leaf::GetRoom()
{
	srand((unsigned)time(NULL));
	if (path != NULL)
	{
		return path;
	}
	else
	{
		pair<int, int>* L;
		pair<int, int>* R;
		if (leftChild != NULL)
		{
			L = leftChild->GetRoom();
			/*path_X = m.getRandomNumber(topLineS_X + 1, topLineB_X - 1);
			path_Y = m.getRandomNumber(topLineS_Y + 1, botLineB_Y);*/

		}
		if (rightChild != NULL)
		{
			R = rightChild->GetRoom();
		}
		if (L == NULL && R == NULL)
		{
			return NULL;
		}
		else if (R == NULL)
		{
			return L;
		}
		else if (L == NULL)
		{
			return R;
		}
		else if ((rand()%100) < 50)
		{
			return L;
		}
		else
		{
			return R;
		}
	}
}

void Leaf::CreateHall(pair<int, int>* l, pair<int, int>* r)
{
	srand((unsigned)time(NULL));
	bool vertical = (rand() % 100) > 50;
	//bool vertical = true;
	//if (l->isRoom && r->isRoom)
	//{
	if (l != NULL && r != NULL)
	{
		if (vertical)
		{
			/*GotoXY(0, 40, ' ');
			cout << "l->path_Y: " << l->path_Y << " r->path_Y: " << r->path_Y << endl;
			cout << "l->path_X: " << l->path_X << " r->path_X: " << r->path_X << endl;
			system("pause > null");*/
			for (int v = l->second; v <= r->second; ++v)
			{
				GotoXY(l->first, v, '.');
			}
			for (int h = l->first; h <= r->first; ++h)
			{
				GotoXY(h, r->second, '.');
			}
			/*GotoXY(l->path_X, l->path_Y, 'L');
			GotoXY(r->path_X, r->path_Y, 'R');*/
		}
		else
		{
			for (int h = l->first; h <= r->first; ++h)
			{
				GotoXY(h, r->second, '.');
			}
			for (int v = l->second; v <= r->second; ++v)
			{
				GotoXY(l->first, v, '.');
			}
		}
	}
	//}
	
	/*else
	{
	for (int h = l->path_X; h < r->path_X; ++h)
	{
	GotoXY(h, r->path_Y, 'H');
	}
	for (int v = l->path_Y; v < r->path_Y; ++v)
	{
	GotoXY(l->path_X, v, 'H');
	}
	}*/	
}

bool Leaf::Split()
{
	if (leftChild != NULL || rightChild != NULL)
	{
		return false;
	}

	srand((unsigned)time(NULL));
	bool splitHeight = rand() % 100 > 50;

	if ((y2 - y) < (x2 - x) && (1.3 <= (double)(x2-x) / (double)(y2-y)))
	{
		splitHeight = false;
	}
	else if ((x2 - x) < (y2 - y) && (1.3 <= (double)(y2 - y) / (double)(x2 - x)))
	{
		splitHeight = true;
	}

	int max = ((splitHeight) ? (y2 - y) : (x2 - x)) - MIN_LEAF_SIZE;

	if (max <= MIN_LEAF_SIZE)
	{
		return false;
	}

	MRandom mr;
	int splitRandom = mr.getRandomNumber(MIN_LEAF_SIZE, max);

	if (splitHeight)
	{
		leftChild = new Leaf(x, y, x2, y + splitRandom);
		rightChild = new Leaf(x, y + splitRandom, x2, y2);
	}
	else
	{
		leftChild = new Leaf(x, y, x + splitRandom, y2);
		rightChild = new Leaf(x + splitRandom, y, x2, y2);
	}
	return true;
}
/*
	170816	-> create Room function
			-> create Path
*/




//
//Leaf::~Leaf()
//{
//}
//
//bool Leaf::split()
//{
//	if (leftChild != NULL || rightChild != NULL)
//		return false;
//	
//	srand((unsigned)time(NULL));
//	bool splitHeight = rand()%100 > 50;
//	if ((y2 < x2) && (1.25 <= ((double)x2 / (double)y2)))
//	{
//		splitHeight = false;
//	}
//	else if ((x2 < y2) && (1.25 <= ((double)y2 / (double)x2)))
//	{
//		splitHeight = true;
//	}
//
//	int max = ((splitHeight) ? y2 : x2) - MIN_LEAF_SIZE;
//
//	if (max <= MIN_LEAF_SIZE)
//	{
//		return false;
//	}
//
//	MRandom m;
//	int splitRandom = m.getRandomNumber(MIN_LEAF_SIZE, max);
//
//	if (splitHeight)
//	{
//		leftChild = new Leaf(x, y, x2, splitRandom);
//		rightChild = new Leaf(x, y + splitRandom, x2, y2 - splitRandom);
//	}
//	else
//	{
//		leftChild = new Leaf(x, y, splitRandom, y2);
//		rightChild = new Leaf(x + splitRandom, y, x2 - splitRandom, y2);
//	}
//	return true;
//}
//
//void Leaf::createRooms()
//{
//	if (leftChild != NULL || rightChild != NULL)
//	{
//		if (leftChild != NULL)
//		{
//			leftChild->createRooms();
//		}
//		else
//		{
//			rightChild->createRooms();
//		}
//	}
//	else
//	{
//
//	}
//}
//
////// this Leaf is the ready to make a room
////var roomSize : Point;
////var roomPos : Point;
////// the room can be between 3 x 3 tiles to the size of the leaf - 2.
////roomSize = new Point(Registry.randomNumber(3, x2 - 2), Registry.randomNumber(3, y2 - 2));
////// place the room within the Leaf, but don't put it right 
////// against the side of the Leaf (that would merge rooms together)
////roomPos = new Point(Registry.randomNumber(1, x2 - roomSize.x - 1), Registry.randomNumber(1, y2 - roomSize.y - 1));
////room = new Rectangle(x + roomPos.x, y + roomPos.y, roomSize.x, roomSize.y);
//
//void Leaf::printLeaf()
//{
//	// (0,0)------------------(10,0) y는 일정
//	// (0,0) | (0, 10)	x는 일정
//	for (int i = (x < x2) ? x : x2; (x < x2) ? (i < x2 - x) : (i < x - x2); ++i)
//	{
//		gotoxy(i, y, 'O');
//	}
//	for (int i = (x < x2) ? x : x2; (x < x2) ? (i < x2 - x) : (i < x - x2); ++i)
//	{
//		gotoxy(i, y2, 'O');
//	}
//	for (int i = (y < y2) ? y : y2; (y < y2) ? (i < y2 - y) : (i < y - y2); ++i)
//	{
//		gotoxy(x, i, 'O');
//	}
//	for (int i = (y < y2) ? y : y2; (y < y2) ? (i < y2 - y) : (i < y - y2); ++i)
//	{
//		gotoxy(x2, i, 'O');
//	}
//	gotoxy(0, 21, ' ');
//	cout << "leaf start x,y: " << x << ", " << y << endl;
//	cout << "leaf end x,y: " << x2 << ", " << y2 << endl;
//}