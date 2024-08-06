#include "Function.h"

#define MenuX 57
#define MenuY 15
#define hurdleY 35

void GameEnd()
{
	Clear();
	GotoXY(MenuX, MenuY);
	printf("게임이 종료되었습니다.\n");
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

void GameStartMenu()
{
	GotoXY(MenuX, MenuY - 2);		printf("1.게임시작\n");
	GotoXY(MenuX, MenuY - 1);		printf("\n");
	GotoXY(MenuX, MenuY);			printf("2.기록보기\n");
	GotoXY(MenuX, MenuY + 1);		printf("\n");
	GotoXY(MenuX, MenuY + 2);		printf("3.게임종료\n");

	int playerInput = 0;
	scanf_s("%d", &playerInput);

	if (playerInput == 1)
	{

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

