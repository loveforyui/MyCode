// BT.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

Tree<int>* Tree<int>::inst = NULL;

int main()
{
    Tree<int>::getinst()->insert(1);
    Tree<int>::getinst()->insert(2);
    Tree<int>::getinst()->insert(3);

    return 0;
}

