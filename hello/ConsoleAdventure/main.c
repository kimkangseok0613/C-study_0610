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
	// 플레이어와 아이템의 위치가 같은지 판별
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
	printf("콘솔 모험");
	Clear();

	SetConsoleSize(50,50);
	SetConsoleCursorVisibility(0); // 1이 되면 true, 0이 되면 false

	// 플레이어의 정보
	int playerX = 15, playerY = 15;		// 플레이어의 시작 좌표
	bool itemFound = false;				// 아이템을 발견하면 true로 만들어준다.

	int itemX = 8, itemY = 8;

	int wallX = 1, wallY = 1;			// 벽 위치
	if (wallX = 1)
	{
		wallY--;
	}


	// 게임이 시작하자마자 종료되는 이슈 -> 무한 반복문
	while (1)
	{
		Clear();
		GoToTargetPos(playerX, playerY, "@");
		GoToTargetPos(wallX, wallY,"#");		// 벽 만들기

		InputProcess(&playerX,&playerY); // 플레이어의 입력을 받아서 움직이는 함수.
		InterActother(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player의 위치와 item의 위치가 같을때
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else 
		{
			GoToTargetPos(1, 30, "아이템을 획득했습니다.");
		}

		Sleep(50);

	}

}