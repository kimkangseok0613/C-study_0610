#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "Function.h"

#define filename "Running Record.txt"

void GamePlay()
{

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
		fprintf(fp, "%s %s %s\n", running[i].score);
	}

	fclose(fp);
}

int main()
{
	int playerInput = 0;

	while (1)
	{
		// 1. 게임시작
		// 2. 기록보기
		// 3. 게임종료

		printf("1.게임시작\n");
		printf("\n");
		printf("2.기록보기\n");
		printf("\n");
		printf("3.게임종료\n");

		scanf_s("%d", &playerInput);

		if (playerInput == 1)
		{
			GamePlay();
		}
		if (playerInput == 2)
		{
			ReadRecord();
		}
		if (playerInput == 3)
		{
			break;
		}
	}
}