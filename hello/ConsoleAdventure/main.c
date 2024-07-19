#include <stdio.h>
#include "Console.h"
#include <stdbool.h>

#define ROWS 30	// ����
#define COLS 30	// ���� collumn

char map[COLS][ROWS] = { 0 };		// �� �ȿ��ִ� ������
// ROWS + 1 : ���� ���� '\n' �����ذ�.
// (COLS X ROWS)+1 : �� ���� '\0' �����ذ�.
char mapString[(COLS * (ROWS+1)) + 1];	// �����ͷκ��� ����ϴ� ���ڿ�



void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)
	{
		if (*x < 2)*x = 2;
		*x -= 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 28) *x = 28;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 2)*y = 2;
		*y-=1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*y > 28)*y = 28;
		*y+=1;
	}
}

void InterActother(int* playerX, int* playerY, int* itemX, int* itemY, bool* item)
{
	// �÷��̾�� �������� ��ġ�� ������ �Ǻ�
	if (*playerX == *itemX && *playerY == *itemY)
	{
		*item = true;
	}
}

void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s",s);
}

void MakeMap(char Wall, char(*map)[ROWS])
{
	
}

void GameInfo()	// ������ ������ ����ϴ� �Լ��� ���.
{

}


int main()
{
	printf("�ܼ� ����");
	Clear();

	SetConsoleSize(50,50);
	SetConsoleCursorVisibility(0); // 1�� �Ǹ� true, 0�� �Ǹ� false

	// �÷��̾��� ����
	int playerX = 15, playerY = 15;		// �÷��̾��� ���� ��ǥ
	bool itemFound = false;				// �������� �߰��ϸ� true�� ������ش�.

	int itemX = 8, itemY = 8;

	// ���� �� ����
	// MakeMap();

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)
	{
		map[i][0] = '#';
		map[i][ROWS-1] = '#';
	}
	for (int i = 0; i < ROWS; ++i)
	{
		map[0][i] = '#';
		map[COLS - 1][i] = '#';
	}

	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex++] = map[i][j];
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';

	// ������ �������ڸ��� ����Ǵ� �̽� -> ���� �ݺ���
	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX,&playerY); // �÷��̾��� �Է��� �޾Ƽ� �����̴� �Լ�.
		InterActother(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player�� ��ġ�� item�� ��ġ�� ������
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else 
		{
			GoToTargetPos(1, 31, "�������� ȹ���߽��ϴ�.");
		}


		Sleep(50);

	}

}