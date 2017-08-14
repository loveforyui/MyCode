#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Leaf.h"

using namespace std;
void printLeafs(vector<Leaf>& _leafs);
void main()
{
	const int MAX_ARRAY_Y = 20;
	const int MAX_ARRAY_X = 20;
	const int MAX_LEAF_SIZE = 5;
	vector<Leaf> _leafs;
	Leaf root(0, 0, MAX_ARRAY_X, MAX_ARRAY_Y);
	_leafs.push_back(root);

	srand((unsigned)time(NULL));

	bool isSplit = true;
	while (isSplit)
	{
		isSplit = false;

		for (vector<Leaf>::size_type i = 0; i < _leafs.size(); ++i)
		{
			if (_leafs[i].leftChild == NULL && _leafs[i].rightChild == NULL)
			{
				if (MAX_LEAF_SIZE < _leafs[i].width || MAX_LEAF_SIZE < _leafs[i].height || 75 < rand() % 100)
				{
					if (_leafs[i].split())
					{
						_leafs.push_back(*_leafs[i].leftChild);
						_leafs.push_back(*_leafs[i].rightChild);
						isSplit = true;
					}
				}
			}
		}
		/*for each (Leaf var in _leafs)
		{
			if (var.leftChild == NULL && var.rightChild == NULL)
			{
				if (MAX_LEAF_SIZE < var.width || MAX_LEAF_SIZE < var.height || 75 < rand() % 100)
				{
					if (var.split())
					{
						_leafs.push_back(*var.leftChild);
						_leafs.push_back(*var.rightChild);
						isSplit = true;
					}
				}
			}
		}*/
	}
	
	printLeafs(_leafs);
	system("pause>null");
}

void printLeafs(vector<Leaf>& _leafs)
{
	for (vector<Leaf>::size_type i = 0 ; i < _leafs.size(); ++i)
	{
		//cout << "vector: " << i << endl;
		system("cls");
		_leafs[i].printLeaf();

		system("pause");
	}
}
