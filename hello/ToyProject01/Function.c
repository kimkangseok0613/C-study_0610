#include "Function.h"

#define MenuX 105
#define MenuY 18
#define hurdleY 35


void GameStartMenu()
{
	GotoXY(MenuX, MenuY);			printf("1.���ӽ���\n");
	GotoXY(MenuX, MenuY + 1);		printf("\n");
	GotoXY(MenuX, MenuY + 2);		printf("2.��Ϻ���\n");
	GotoXY(MenuX, MenuY + 3);		printf("\n");
	GotoXY(MenuX, MenuY + 4);		printf("3.��������\n");
}

void GameEnd()
{
	Clear();
	GotoXY(50, 15);
	printf("������ ����Ǿ����ϴ�.\n");
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