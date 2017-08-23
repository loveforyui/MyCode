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