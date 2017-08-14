#include "Leaf.h"


void Leaf::PrintLeaf()
{
	//TopLineDrawing
	for (int i = this->topLineS_X; i < this->topLineB_X; ++i)
	{
		GotoXY(i, this->topLineS_Y, 'x');
	}
	//BottomLineDrawing
	for (int in = this->topLineS_X; in < this->topLineB_X; ++in)
	{
		GotoXY(in, this->botLineS_Y, 'x');
	}
	//LeftLineDrawing
	for (int ik = this->topLineS_Y; ik < this->botLineS_Y; ++ik)
	{
		GotoXY(this->topLineS_X, ik, 'x');
	}
	//RightLineDrawing
	for (int ig = this->topLineS_Y; ig <= this->botLineS_Y; ++ig)
	{
		GotoXY(this->topLineB_X, ig, 'x');
	}

	GotoXY(0, 31, ' ');
	cout << "x: " << x << " y: " << y << " x2: " << x2 << " y2: " << y2 << endl;

	//system("pause > NULL");
}

void Leaf::GotoXY(int x, int y, const char c)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	cout << c;
}

Leaf::~Leaf()
{
}

bool Leaf::Split()
{
	if (leftChild != NULL || rightChild != NULL)
	{
		return false;
	}

	srand((unsigned)time(NULL));
	bool splitHeight = rand() % 100 > 50;

	if ((y2 - y) < (x2 - x) && (1.25 <= (double)(x2-x) / (double)(y2-y)))
	{
		splitHeight = false;
	}
	else if ((x2 - x) < (y2 - y) && (1.25 <= (double)(y2 - y) / (double)(x2 - x)))
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