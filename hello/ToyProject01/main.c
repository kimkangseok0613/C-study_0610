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
#define ROWS 25	// ����
#define COLS 15 // ����

char DinoString[(COLS * (ROWS + 1)) + 1];
char DinoData[COLS][ROWS] = { 0 };


void MakeDino(char Wall, char(*map)[ROWS]) // 2���� �迭, �ʿ� �����ϴ� ������ ����
{
	for (int i = 0; i < COLS; ++i)	// ���� x ���� �� ����
	{
		for (int j = 0; j < 15; ++j)
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

int hurdle = 115;
int dinoY = 15;

void Crashing()
{
	// ������ x,y��ǥ�� ����� x,y��ǥ�� ������ ������ �����.
	if (dinoY == hurdleY && 0 == hurdle)
	{
		Clear();
		printf("������ ����Ǿ����ϴ�. 4���� �����ּ���");
		
	}
}

void GamePlay()
{

}

void makedino()
{
	char string1 = "               @@@@@@@   \n";
	strcpy_s(DinoData[0], ROWS, string1);
	char string2 = "              @@@@@@@@@  \n";
	strcpy_s(DinoData[1], ROWS, string2);
	char string3 = "             @@@ @@@@@   \n";
	strcpy_s(DinoData[1], ROWS, string3);
	char string4 = "             @@@@@@@@@@@ \n";
	strcpy_s(DinoData[1], ROWS, string4);
	char string5 = "             @@@@@@      \n";
	strcpy_s(DinoData[1], ROWS, string5);
	char string6 = "    *       @@@@@@@@@@@  \n";
	strcpy_s(DinoData[1], ROWS, string6);
	char string7 = "    @      @@@@@@        \n";
	strcpy_s(DinoData[1], ROWS, string7);
	char string8 = "    @@    @@@@@@@@@@@@@@ \n";
	strcpy_s(DinoData[1], ROWS, string8);
	char string9 = "    @@@@ @@@@@@@@@@@   @ \n";
	strcpy_s(DinoData[1], ROWS, string9);
	char string10 = "     @@@@@@@@@@@@@@@     \n";
	strcpy_s(DinoData[1], ROWS, string10);
	char string11 = "      @@@@@@@@@@@@@@     \n";
	strcpy_s(DinoData[1], ROWS, string11);
	char string12 = "       @@@@@@@@@@@@      \n";
	strcpy_s(DinoData[1], ROWS, string12);
	char string13 = "        @@@@@ @@@@@      \n";
	strcpy_s(DinoData[1], ROWS, string13);
	char string14 = "         @@    @@        \n";
	strcpy_s(DinoData[1], ROWS, string14);
	char string15 = "         @@@@  @@@@      \n";
	strcpy_s(DinoData[1], ROWS, string15);
}


void ReadRecord(Running *running,int count)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("���� ���� ����!\n");
	}
	for (int i = 0; i < count; ++i)
	{
		fprintf(fp, "%s\n", running[i].score);
	}

	fclose(fp);
}

int main()
{
	SetConsoleSize(120, 30);
	SetConsoleCursorVisibility(0);

	int score = 0;
	
	GameStartMenu();

	while (true)
	{
		// 1. ���ӽ���
		// 2. ��Ϻ���
		// 3. ��������

		Clear();

		GotoXY(3, 3);
		printf("SCORE : %d", score);
		score++;

		// ����
		makedino();


		// ��ֹ�
		



		Sleep(20);
	}
}