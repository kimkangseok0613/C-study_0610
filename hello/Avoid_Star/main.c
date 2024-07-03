#include <stdio.h>		// printf, scanf 함수를 사용하기 위해서 필요한다.		// 시스템 폴더의 헤더파일을 불러온다.
#include "Console.h"	// 프로젝트 안에 ""안에 있는 파일을 찾아서 복사해라.
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>		// consloe in out	

#define MAX 30	// 전처리기로 MAX 숫자에 값을 10으로 전부 치환하는 코드 (컴파일 시점에)
#define BG 15

void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("별피하기");
		GotoXY(5, 20);
		printf("please press any key");

		if (_kbhit())
			break;
	}
}

void Bomb(void)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_CONTROL) & 8001)
			Clear;
	}
}
void GameOver(void)
{
	int temp = 0;
	printf("GAME OVER\n");
	printf("게임을 종료하려면 아무키를 입력하고 ENTER키를 쳐주세요.\n");
	scanf_s("%d", &temp);
}

int main()
{
	SetTitle("별피하기_김강석");
	SetColor(BG,0);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	int score = 0;

	int x = 14, y = 28;
	int bx = 0, by = 0;
	bool bullet = false;
	bool IsLve = true;	// 플레이어가 현재 죽지 않음을 나타냄.

#if false
	int ex = 0, ey = 0;
	bool enemy = false;
#endif
	int ex[MAX] = { 0 };
	int ey[MAX] = { 0 };
	bool enemy[MAX] = { false };
	srand(time(NULL));

	StartMenu();

#if true
	while (true)
	{
		Clear();

		GotoXY(0, 0);
		printf("SCORE : %d", score);
		score++;
#if false
		if (!enemy)
		{
			srand(time(NULL) * 2);
			ex = (rand() % 15)*2;
			ey = 0;
			enemy = true;
		}
#endif
		for (int i = 0; i < MAX; i++)
		{
			if (!enemy[i])
			{
				ex[i] = (rand() % 15) * 2;
				ey[i] = 1;
				enemy[i] = true;
				break;
			}
		}



		if (GetAsyncKeyState(VK_LEFT) & 8001)
		{
			if (x < 2)x = 2;
			x-=2;	
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 26) x = 26;
			x+=2;
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 1)y = 1;
			y--;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{
			if (y >28)y = 28;
			y++;
		}
#endif
#if true
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		
		if (!bullet)
		{
				bx = x;
				by = y - 1;
				bullet = true;
		}
		if (bullet)
		{
				by--;
				GotoXY(bx, by);
				printf("↑");

				if (by < 1)
					bullet = false;
		}
#endif
#if false		
		if (enemy)
		{
			GotoXY(ex, ey);
			printf("★");
			ey++;
			
			if (ey > 28)
			{
				enemy = false;
			}
		}
		

#endif
		for (int i = 0;i < MAX;i++)
		{
			if (enemy[i])
			{
				SetColor(BG,12);
				GotoXY(ex[i], ey[i]);
				printf("☆");
				ey[i]++;

				//bx, by 총알과 별의 좌표가 같으면 bool값 false
				if (ey[i] == by && ex[i]==bx && bullet)
				{
					enemy[i] = false;
					bullet = false;
				}

				if (x == ex[i] && y == ey[i])
				{
					if (IsLve)// 플레이어가 죽었을때 작동하는 로직
					{
						IsLve = false;
					}
				}

				if (ey[i] > 28)
					enemy[i] = false;
			}
			
		}
		//플레이어가 살아있을때 현재 플레이어의 위치에 ▲출력해주는 코드
		if (IsLve)
		{
			SetColor(BG, 12);
			GotoXY(x, y);
			printf("▲");
		}
		else
		{
			GotoXY(x, y);
			printf("@");
		
			break;
		}
		Sleep(100);	//숫자만큼 기다렸다가 다시 실행한다.
	}
	GameOver();
}