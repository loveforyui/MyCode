#include "Leaf.h"

Leaf::~Leaf()
{
}

bool Leaf::split()
{
	if (leftChild != NULL || rightChild != NULL)
		return false;
	
	srand((unsigned)time(NULL));
	bool splitHeight = rand()%100 > 50;
	if ((height < width) && (1.25 <= ((double)width / (double)height)))
	{
		splitHeight = false;
	}
	else if ((width < height) && (1.25 <= ((double)height / (double)width)))
	{
		splitHeight = true;
	}

	int max = ((splitHeight) ? height : width) - MIN_LEAF_SIZE;

	if (max <= MIN_LEAF_SIZE)
	{
		return false;
	}

	MRandom m;
	int splitRandom = m.getRandomNumber(MIN_LEAF_SIZE, max);

	if (splitHeight)
	{
		leftChild = new Leaf(x, y, width, splitRandom);
		rightChild = new Leaf(x, y + splitRandom, width, height - splitRandom);
	}
	else
	{
		leftChild = new Leaf(x, y, splitRandom, height);
		rightChild = new Leaf(x + splitRandom, y, width - splitRandom, height);
	}
	return true;
}

void Leaf::createRooms()
{
	if (leftChild != NULL || rightChild != NULL)
	{
		if (leftChild != NULL)
		{
			leftChild->createRooms();
		}
		else
		{
			rightChild->createRooms();
		}
	}
	else
	{

	}
}

//// this Leaf is the ready to make a room
//var roomSize : Point;
//var roomPos : Point;
//// the room can be between 3 x 3 tiles to the size of the leaf - 2.
//roomSize = new Point(Registry.randomNumber(3, width - 2), Registry.randomNumber(3, height - 2));
//// place the room within the Leaf, but don't put it right 
//// against the side of the Leaf (that would merge rooms together)
//roomPos = new Point(Registry.randomNumber(1, width - roomSize.x - 1), Registry.randomNumber(1, height - roomSize.y - 1));
//room = new Rectangle(x + roomPos.x, y + roomPos.y, roomSize.x, roomSize.y);

void Leaf::printLeaf()
{
	// (0,0)------------------(10,0) y는 일정
	// (0,0) | (0, 10)	x는 일정
	for (int i = (x < width) ? x : width; (x < width) ? (i < width - x) : (i < x - width); ++i)
	{
		gotoxy(i, y, 'O');
	}
	for (int i = (x < width) ? x : width; (x < width) ? (i < width - x) : (i < x - width); ++i)
	{
		gotoxy(i, height, 'O');
	}
	for (int i = (y < height) ? y : height; (y < height) ? (i < height - y) : (i < y - height); ++i)
	{
		gotoxy(x, i, 'O');
	}
	for (int i = (y < height) ? y : height; (y < height) ? (i < height - y) : (i < y - height); ++i)
	{
		gotoxy(width, i, 'O');
	}
	gotoxy(0, 21, ' ');
	cout << "leaf start x,y: " << x << ", " << y << endl;
	cout << "leaf end x,y: " << width << ", " << height << endl;
}
void Leaf::gotoxy(int x, int y, const char c)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	cout << c;
}
