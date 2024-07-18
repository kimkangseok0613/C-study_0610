#include <stdio.h>
#include "Console.h"
#include <stdbool.h>

char map[100] = "##########";

void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)
	{
		if (*x < 1)*x = 1;
		*x -= 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 28) *x = 28;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 1)*y = 1;
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

	int wallX = 1, wallY = 1;			// �� ��ġ
	if (wallX = 1)
	{
		wallY--;
	}


	// ������ �������ڸ��� ����Ǵ� �̽� -> ���� �ݺ���
	while (1)
	{
		Clear();
		GoToTargetPos(playerX, playerY, "@");
		GoToTargetPos(wallX, wallY,"#");		// �� �����

		InputProcess(&playerX,&playerY); // �÷��̾��� �Է��� �޾Ƽ� �����̴� �Լ�.
		InterActother(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player�� ��ġ�� item�� ��ġ�� ������
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else 
		{
			GoToTargetPos(1, 30, "�������� ȹ���߽��ϴ�.");
		}

		Sleep(50);

	}

}