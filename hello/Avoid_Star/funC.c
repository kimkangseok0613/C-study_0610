#include "main.h"

void SelectStartMenu() // 게임시작메뉴
{
	printf("1.게임 시작\n");
	printf("2.게임 기록\n");
	printf("3.게임 종료\n");
	int selectmenu = 1;
	scanf_s("%d", &selectmenu);
	if (selectmenu == 1)
	{
		printf("게임을 시작했습니다.\n");
	}
	else if (selectmenu == 2)
	{
		SelectStartMenu();
	}
	else if (selectmenu == 3)
	{
		exit(0);
	}
	else
	{
		printf("잘못된 값을 입력하였습니다.\n");
	}
}