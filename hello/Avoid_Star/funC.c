#include "main.h"

void SelectStartMenu() // ���ӽ��۸޴�
{
	printf("1.���� ����\n");
	printf("2.���� ���\n");
	printf("3.���� ����\n");
	int selectmenu = 1;
	scanf_s("%d", &selectmenu);
	if (selectmenu == 1)
	{
		printf("������ �����߽��ϴ�.\n");
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
		printf("�߸��� ���� �Է��Ͽ����ϴ�.\n");
	}
}