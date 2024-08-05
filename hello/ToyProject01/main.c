#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include "Function.h"
#include "Console.h"

#define filename "Running Record.txt"
#define MenuX 105
#define MenuY 18
#define hurdleY 35

int hurdle = 145;
int dinoY = 26;

void GamePlay()
{

}

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
	GotoXY(0, dinoY + 14);		printf("         @@@@  @@@@\n");
}

void makehurdle()
{
	GotoXY(hurdle, hurdleY);				printf("##\n");
	GotoXY(hurdle, hurdleY + 1);			printf("##\n");
	GotoXY(hurdle, hurdleY + 2);			printf("##\n");
	GotoXY(hurdle, hurdleY + 3);			printf("##\n");
	GotoXY(hurdle, hurdleY + 4);			printf("##\n");
}

void erasehredle()
{
	GotoXY(hurdle, hurdleY);				printf("  \n");
	GotoXY(hurdle, hurdleY + 1);			printf("  \n");
	GotoXY(hurdle, hurdleY + 2);			printf("  \n");
	GotoXY(hurdle, hurdleY + 3);			printf("  \n");
	GotoXY(hurdle, hurdleY + 4);			printf("  \n");
}

void Hurdle()
{
	hurdle--;
	erasehredle();
	makehurdle();

	if (hurdle == 0)
		hurdle = 145;
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

int main()
{
	SetConsoleSize(220, 40);
	SetConsoleCursorVisibility(0);

	int playerInput = 0;
	int score = 0;
	bool hurdle = true;
	bool Islive = true;

	int hx[100] = { 0 };
	//bool hurdle[100] = { true };
	
	GameStartMenu();

	while (true)
	{
		// 1. 게임시작
		// 2. 기록보기
		// 3. 게임종료

		

		scanf_s("%d", &playerInput);

		if (playerInput == 1)
		{
			Clear();

			GotoXY(3, 3);
			printf("SCORE : %d", score);
			score++;

			// 공룡
			makedino();


			// 장애물
			Hurdle();


			//Sleep(20);
			

		}
		if (playerInput == 2)
		{
			//ReadRecord();
		}
		if (playerInput == 3)
		{
			GameEnd();
		}
	}
}