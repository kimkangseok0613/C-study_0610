#include <stdio.h>
#include "Console.h"
#include <stdbool.h>

#define ROWS 30	// 가로
#define COLS 30	// 세로 collumn

char map[COLS][ROWS] = { 0 };		// 맵 안에있는 데이터
// ROWS + 1 : 개행 문자 '\n' 더해준것.
// (COLS X ROWS)+1 : 널 문자 '\0' 더해준것.
char mapString[(COLS * (ROWS+1)) + 1];	// 데이터로부터 출력하는 문자열



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

void MakeMap(char Wall, char(*map)[ROWS]) // 2차원 배열, 맵에 존재하는 데이터 설정
{
	for (int i = 0; i < COLS; ++i)	// 세로 x 가로 빈 공간
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)	
	{
		map[i][0] = Wall;
		map[i][ROWS - 1] = Wall;
	}
	for (int i = 0; i < ROWS; ++i)
	{
		map[0][i] = Wall;
		map[COLS - 1][i] = Wall;
	}
}
void RenderMap()
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex++] = map[i][j];
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';	}


void GameInfo()	// 게임의 정보를 출력하는 함수를 담당.
{

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
	bool canMove = true;				// true일때만 움직여라(벽에 안 부딪힘)

	int itemX = 8, itemY = 8;

	// 게임 맵 세팅


	// 테두리(외벽) 설정
	MakeMap('#',map);

	// 내벽 데이터 넣어주기.
	map[10][10] = '#';

	RenderMap();

	// 게임이 시작하자마자 종료되는 이슈 -> 무한 반복문
	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX,&playerY); // 플레이어의 입력을 받아서 움직이는 함수.
		InterActother(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player의 위치와 item의 위치가 다를때
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else 
		{
			GoToTargetPos(1, 31, "아이템을 획득했습니다.");
		}

		if (!canMove) //벽에 부딪힘
		{
			if (playerX == itemX && playerY == itemY)
				canMove = false;
		}
		else
		{
			canMove = true;
		}

		Sleep(50);

	}

}