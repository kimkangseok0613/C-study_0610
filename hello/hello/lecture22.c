/*
*	�ۼ���	: 2024-07-19
*	�ۼ���	: �谭��
*	�н���ǥ	: 2���� �迭�� ����
*/

// 1. ����
// �ڷ��� �迭�̸� [����ũ��][����ũ��]

#include "lectures.h"

void lecture22()
{
	int numArr[3][4] =
	{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	int numArr2[3][4] = { 0 };

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			numArr2[i][j] = 10;
			printf("%d ", numArr2[i][j]);
		}
	}
	printf("\n");

	char map[10][10] = { 0 };

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		map[i][0] = '#';
		map[i][9] = '#';
	}

	//for (int j = 0; j < 10; ++j)
	//{
	//	map[0][j] = '#';
	//	map[9][j] = '#';
	//}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

}