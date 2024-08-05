#include "Function.h"

#define MenuX 105
#define MenuY 18
#define hurdleY 35


void GameStartMenu()
{
	GotoXY(MenuX, MenuY);			printf("1.게임시작\n");
	GotoXY(MenuX, MenuY + 1);		printf("\n");
	GotoXY(MenuX, MenuY + 2);		printf("2.기록보기\n");
	GotoXY(MenuX, MenuY + 3);		printf("\n");
	GotoXY(MenuX, MenuY + 4);		printf("3.게임종료\n");
}

void GameEnd()
{
	Clear();
	GotoXY(50, 15);
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