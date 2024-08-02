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
		perror("���� ���� ����!\n");
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
		// 1. ���ӽ���
		// 2. ��Ϻ���
		// 3. ��������

		printf("1.���ӽ���\n");
		printf("\n");
		printf("2.��Ϻ���\n");
		printf("\n");
		printf("3.��������\n");

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