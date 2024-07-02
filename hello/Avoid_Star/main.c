#include <stdio.h>		// printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��Ѵ�.		// �ý��� ������ ��������� �ҷ��´�.
#include "Console.h"	// ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�.
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10	// ��ó����� MAX ���ڿ� ���� 10���� ���� ġȯ�ϴ� �ڵ� (������ ������)

int main()
{
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	int x = 14, y = 28;
	int bx = 0, by = 0;
	bool bullet = false;

#if false
	int ex = 0, ey = 0;
	bool enemy = false;
#endif
	int ex[MAX] = { 0 };
	int ey[MAX] = { 0 };
	bool enemy[MAX] = { false };
	srand(time(NULL));

#if true
	while (true)
	{
		Clear();
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
				ey[i] = 0;
				enemy[i] = true;
				break;
			}
		}



		if (GetAsyncKeyState(VK_LEFT) & 8001)
		{
			if (x < 1)x = 1;
			x--;	//
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 27) x = 27;
			x++;
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
		GotoXY(x, y);
		printf("��");
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
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;

				if (ey[i] > 28)
					enemy[i] = false;
			}
		}

		Sleep(100);
	}
}