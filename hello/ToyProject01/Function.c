#include "Function.h"

#define MenuX 57
#define MenuY 15
#define hurdleY 35

void GameEnd()
{
	Clear();
	GotoXY(MenuX, MenuY);
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

void GameStartMenu()
{
	GotoXY(MenuX, MenuY - 2);		printf("1.���ӽ���\n");
	GotoXY(MenuX, MenuY - 1);		printf("\n");
	GotoXY(MenuX, MenuY);			printf("2.��Ϻ���\n");
	GotoXY(MenuX, MenuY + 1);		printf("\n");
	GotoXY(MenuX, MenuY + 2);		printf("3.��������\n");

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

