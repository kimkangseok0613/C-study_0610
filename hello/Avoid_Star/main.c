#include <stdio.h>		// printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��Ѵ�.		// �ý��� ������ ��������� �ҷ��´�.
#include "Console.h"	// ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�.
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>		// consloe in out	

#define MAX 30	// ��ó����� MAX ���ڿ� ���� 10���� ���� ġȯ�ϴ� �ڵ� (������ ������)
#define BG 15

void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("�����ϱ�");
		GotoXY(5, 20);
		printf("please press any key");

		if (_kbhit())
			break;
	}
}

void Bomb(void)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_CONTROL) & 8001)
			Clear;
	}
}
void GameOver(void)
{
	int temp = 0;
	printf("GAME OVER\n");
	printf("������ �����Ϸ��� �ƹ�Ű�� �Է��ϰ� ENTERŰ�� ���ּ���.\n");
	scanf_s("%d", &temp);
}

int main()
{
	SetTitle("�����ϱ�_�谭��");
	SetColor(BG,0);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	int score = 0;

	int x = 14, y = 28;
	int bx = 0, by = 0;
	bool bullet = false;
	bool IsLve = true;	// �÷��̾ ���� ���� ������ ��Ÿ��.

#if false
	int ex = 0, ey = 0;
	bool enemy = false;
#endif
	int ex[MAX] = { 0 };
	int ey[MAX] = { 0 };
	bool enemy[MAX] = { false };
	srand(time(NULL));

	StartMenu();

#if true
	while (true)
	{
		Clear();

		GotoXY(0, 0);
		printf("SCORE : %d", score);
		score++;
#if false
		if (!enemy)
		{
			srand(time(NULL) * 2);
			ex = (rand() % 15)*2;
			ey = 0;
			enemy = true;
		}
#endif
		for (int i = 0; i < MAX; i++)
		{
			if (!enemy[i])
			{
				ex[i] = (rand() % 15) * 2;
				ey[i] = 1;
				enemy[i] = true;
				break;
			}
		}



		if (GetAsyncKeyState(VK_LEFT) & 8001)
		{
			if (x < 2)x = 2;
			x-=2;	
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 26) x = 26;
			x+=2;
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 1)y = 1;
			y--;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{
			if (y >28)y = 28;
			y++;
		}
#endif
#if true
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		
		if (!bullet)
		{
				bx = x;
				by = y - 1;
				bullet = true;
		}
		if (bullet)
		{
				by--;
				GotoXY(bx, by);
				printf("��");

				if (by < 1)
					bullet = false;
		}
#endif
#if false		
		if (enemy)
		{
			GotoXY(ex, ey);
			printf("��");
			ey++;
			
			if (ey > 28)
			{
				enemy = false;
			}
		}
		

#endif
		for (int i = 0;i < MAX;i++)
		{
			if (enemy[i])
			{
				SetColor(BG,12);
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;

				//bx, by �Ѿ˰� ���� ��ǥ�� ������ bool�� false
				if (ey[i] == by && ex[i]==bx && bullet)
				{
					enemy[i] = false;
					bullet = false;
				}

				if (x == ex[i] && y == ey[i])
				{
					if (IsLve)// �÷��̾ �׾����� �۵��ϴ� ����
					{
						IsLve = false;
					}
				}

				if (ey[i] > 28)
					enemy[i] = false;
			}
			
		}
		//�÷��̾ ��������� ���� �÷��̾��� ��ġ�� ��������ִ� �ڵ�
		if (IsLve)
		{
			SetColor(BG, 12);
			GotoXY(x, y);
			printf("��");
		}
		else
		{
			GotoXY(x, y);
			printf("@");
		
			break;
		}
		Sleep(100);	//���ڸ�ŭ ��ٷȴٰ� �ٽ� �����Ѵ�.
	}
	GameOver();
}