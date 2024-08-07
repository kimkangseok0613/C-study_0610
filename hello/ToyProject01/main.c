#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include "Function.h"
#include "Console.h"
#include "string.h"

#define filename "Running Record.txt"
#define MenuX 57
#define MenuY 13
#define hurdleY 25
#define ROWS 2	// 가로
#define COLS 1 // 세로
#define hurdle  115
#define dinoY  15

char HurdleString[(COLS * (ROWS + 1)) + 1];
char Hurdle[COLS][ROWS] = { 0 };

void StopGame()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 8001)
	{
		GotoXY(MenuX, MenuY);
		printf("게임을 멈췄습니다");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		exit(0);
	}
}


//void MakeDino(char dino, char(*map)[ROWS]) // 2차원 배열, 맵에 존재하는 데이터 설정
//{
//	for (int i = 0; i < COLS; ++i)	// 세로 x 가로 빈 공간
//	{
//		for (int j = 0; j < 15; ++j)
//		{
//			map[i][j] = ' ';
//		}
//	}
//
//	for (int i = 0; i < COLS; ++i)
//	{
//		map[i][0] = dino;
//		map[i][ROWS - 1] = dino;
//	}
//	for (int i = 0; i < ROWS; ++i)
//	{
//		map[0][i] = dino;
//		map[COLS - 1][i] = dino;
//	}
//}

void RenderHurdle()
{
	int dinoIndex = 0;


	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			HurdleString[dinoIndex++] = Hurdle[i][j];
		}

		if(i == COLS - 1){
			HurdleString[dinoIndex] = ' ';
		}
		HurdleString[dinoIndex++] = '\n';
	}
	HurdleString[dinoIndex] = '\0';
}


void Crashing()
{
	// 공룡의 x,y좌표와 허들의 x,y좌표가 같으면 게임이 멈춘다.
	if (dinoY == hurdleY && 0 == hurdle)
	{
		Clear();
		printf("게임이 종료되었습니다. 4번을 눌려주세요");
		
	}
}

void MakeHurdle(char HurdlesData, char(*Hurdle)[ROWS])
{
	for (int i = 0; i < COLS; ++i) {
		
		for (int j = 0; j < ROWS; ++j) {
			Hurdle[i][j] = HurdlesData;
		}
	}

}

// 공룡 장애물.  가로 크기
// 첫번째 줄 크기 : 공룡 장애물 x + 가로 x
// 마지막 줄 크기 : 
// 데이터


void makedino()
{
	GotoXY(0, dinoY);			printf("               @@@@@@@\n");
	GotoXY(0, dinoY + 1);		printf("              @@@@@@@@@\n");
	GotoXY(0, dinoY + 2);		printf("             @@@ @@@@@\n");
	GotoXY(0, dinoY + 3);		printf("             @@@@@@@@@@@\n");
	GotoXY(0, dinoY + 4);		printf("             @@@@@@\n");
	GotoXY(0, dinoY + 5);		printf("    *       @@@@@@@@@@@\n");
	GotoXY(0, dinoY + 6);		printf("    @      @@@@@@\n");
	GotoXY(0, dinoY + 7);		printf("    @@    @@@@@@@@@@@@@@\n");
	GotoXY(0, dinoY + 8);		printf("    @@@@ @@@@@@@@@@@   @\n");
	GotoXY(0, dinoY + 9);		printf("     @@@@@@@@@@@@@@@\n");
	GotoXY(0, dinoY + 10);		printf("      @@@@@@@@@@@@@@\n");
	GotoXY(0, dinoY + 11);		printf("       @@@@@@@@@@@@\n");
	GotoXY(0, dinoY + 12);		printf("        @@@@@ @@@@@\n");
	GotoXY(0, dinoY + 13);		printf("         @@    @@\n");
	GotoXY(0, dinoY + 14);		printf("         @@@@  @@@@");

}


void ReadRecord(Running *running,int count)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("파일 쓰기 실패!\n");
	}
	for (int i = 0; i < count; ++i)
	{
		fprintf(fp, "%s\n", running[i].score);
	}

	fclose(fp);
}

void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}

int main()
{
	SetConsoleSize(120, 30);
	SetConsoleCursorVisibility(0);

	int score = 0;
	
	GameStartMenu();

	MakeHurdle('#', Hurdle);
	RenderHurdle();

	while (true)
	{
		// 1. 게임시작
		// 2. 기록보기
		// 3. 게임종료

		Clear();

		GotoXY(0, 1);
		printf("SCORE : %d", score);
		score++;
		GotoXY(0, 0);
		printf("ESC 게임멈춤");

		// 공룡
		makedino();


		// 장애물
		
		GotoXY(115, 26);
		printf("%s", HurdleString);
		GotoXY(115, 27);
		printf("%s", HurdleString);
		GotoXY(115, 28);
		printf("%s", HurdleString);
		GotoXY(115, 329);
		printf("%s", HurdleString);
	
		StopGame();


		Sleep(20);
	}
}