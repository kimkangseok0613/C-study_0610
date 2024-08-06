#include <stdio.h>
#include "Console.h"
#include <stdbool.h>



#define ROWS 30	// ����
#define COLS 30	// ���� collumn
#define filename "Player Data.txt"

char map[COLS][ROWS] = { 0 };		// �� �ȿ��ִ� ������
// ROWS + 1 : ���� ���� '\n' �����ذ�.
// (COLS X ROWS)+1 : �� ���� '\0' �����ذ�.
char mapString[(COLS * (ROWS+1)) + 1];	// �����ͷκ��� ����ϴ� ���ڿ�



void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)
	{
		if (*x < 2)*x = 2;
		*x -= 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 28) *x = 28;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 2)*y = 2;
		*y-=1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*y > 28)*y = 28;
		*y+=1;
	}
}
void InterActother(int* playerX, int* playerY, int* itemX, int* itemY, bool* item)
{
	// �÷��̾�� �������� ��ġ�� ������ �Ǻ�
	if (*playerX == *itemX && *playerY == *itemY)
	{
		*item = true;
	}
}
void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s",s);
}
void MakeMap(char Wall, char(*map)[ROWS]) // 2���� �迭, �ʿ� �����ϴ� ������ ����
{
	for (int i = 0; i < COLS; ++i)	// ���� x ���� �� ����
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)	
	{
		map[i][0] = Wall;
		map[i][ROWS - 1] = Wall;
	}
	for (int i = 0; i < ROWS; ++i)
	{
		map[0][i] = Wall;
		map[COLS - 1][i] = Wall;
	}
}
void RenderMap()
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex++] = map[i][j];
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';	
}
void ShowGameRecord()
{

}
void GameInfo()	// ������ ������ ����ϴ� �Լ��� ���.
{

}
void SelectStartMenu()
{
	printf("1.���ӽ���\n");
	printf("\n");
	printf("2.��Ϻ���\n");
	printf("\n");
	printf("3.��������\n");
}

typedef struct PlayerData
{
	char name[30];	// �̸��� �����ϱ����� �迭
	int score;		// ���� ���·� ������ �����Ѵ�.
}PlayerData;

void SavePlayerData(PlayerData* player, int totalCount)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("���� ���� ����!\n");
	}

	for (int i = 0; i < totalCount; ++i)
	{
		fprintf(fp, "%s %d\n", player[i].name, player[i].score);
	}

	fclose(fp);
}

void LoadPlayerData(PlayerData* player, int* totalcount)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("���� �б� ����!\n");
		return 0;
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}

	fseek(fp, 0, SEEK_SET);	 // fp�� ����Ű�� �ּҸ� ������ �������� �̵�

	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);		//
		if (ch == '\n')
		{
			count++;
		}
	}

	fseek(fp, 0, SEEK_SET);

	*totalcount = count;

	for (int i = 0; i < count; ++i)
	{
		fscanf_s(fp, "%s %d\n", (player + i)->name, 30, &(player + i)->score);
	}

	fclose(fp);
}

int main()
{
	PlayerData allPlayerData[10];
	int totalcount = 0;
	LoadPlayerData(allPlayerData, totalcount);
	printf("%s %d", allPlayerData[0].name, allPlayerData[0].score);

	SelectStartMenu();
	
	SetConsoleSize(50,50);
	SetConsoleCursorVisibility(0); // 1�� �Ǹ� true, 0�� �Ǹ� false

	// �÷��̾��� ����
	int playerX = 15, playerY = 15;		// �÷��̾��� ���� ��ǥ
	bool itemFound = false;				// �������� �߰��ϸ� true�� ������ش�.
	bool canMove = true;				// true�϶��� ��������(���� �� �ε���)

	int itemX = 8, itemY = 8;

	// ���� �� ����


	// �׵θ�(�ܺ�) ����
	MakeMap('#',map);

	// ���� ������ �־��ֱ�.
	map[10][10] = '#';

	RenderMap();

	// ������ �������ڸ��� ����Ǵ� �̽� -> ���� �ݺ���
	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX,&playerY); // �÷��̾��� �Է��� �޾Ƽ� �����̴� �Լ�.
		InterActother(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player�� ��ġ�� item�� ��ġ�� �ٸ���
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else 
		{
			GoToTargetPos(1, 31, "�������� ȹ���߽��ϴ�.");
		}

		if (!canMove) //���� �ε���
		{
			if (playerX == itemX && playerY == itemY)
				canMove = false;
		}
		else
		{
			canMove = true;
		}

		Sleep(50);

	}

}