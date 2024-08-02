#include <stdio.h>
#include <string.h>
#include "Function.h"
#define filename "MonsterData.txt"

// 1. Monster name, region, grade, level ����ü ������ �����ؼ� printf ���
// 2. ����ü �迭, ������ �ݺ������� ���� �迭 ���.
// 3. �迭���ٰ� ����ü �迭 �����͸� �ִ´�.
// 4. char name[100][30] = Monster.name;
//
// �Լ��� ����� ���α׷���
// ��ȯ�� �Լ��̸�() {}
// Call by Value VS Call by Reference

void ShowAllMonsterData(Monster monster[100], int* total)
{
	for (int i = 0; i < *total; ++i)
	{
		printf(" ���� %d��°�� �̸� : %s, ���� : %s, ��� : %s\n", i+1, monster[i].name, monster[i].region, monster[i].grade);
	}
}

void SearchMosterByName(Monster monster[100], int totalMonsterCount)
{
	char searchName[30];
	printf("�˻��ϰ� ���� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", searchName, 30);	// �����Ҵ�, ���α׷� ���� �ڿ� �˻��ϰ� ���� �پ searchName ������ ����.

	for (int i = 0; i < totalMonsterCount; ++i)
	{
		if (Compare(searchName, monster[i].name))
		{
			printf("�ش� �ϴ� ���͸� ã�ҽ��ϴ�.\n");
			printf("%s, %s, %s\n", monster[i].name, monster[i].region, monster[i].grade);
		}
	}

}

void DeleteMonsterName(Monster monster[100], int* totalCount)
{
	
}

void PrintMonsterList(Monster* monsterlist, int totalCount)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("���� ���� ����!\n");
	}
	
	for (int i = 0; i < totalCount; ++i)
	{
		fprintf(fp, "%s %s %s\n", monsterlist[i].name, monsterlist[i].region, monsterlist[i].grade);
	}
	
	fclose(fp);
}

void LoadMonsterData(Monster* monsterlist, int* totalcount)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("���� �б� ����!\n");
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
		fscanf_s(fp, "%s %s %s", (monsterlist + i)->name, 30, (monsterlist + i)->region, 30, (monsterlist + i)->grade, 30);
	}

	fclose(fp);
}

int main()
{
	int playerInput = 0;

	Monster monsterGroup[100];

	char monster_nmae[100][30];
	char monster_region[100][30];
	char monster_grade[100][30];

	int totalMonsterCount = 0; // ���� �����Ϳ� ��� Index�� ����Ǿ� �ִ°�

	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		
		// 1. ���� ������ �߰�
		// 2. ���� ������ ����
		// 3. ���� ������ ����
		// 4. ���α׷� ����
		printf("1. ���� ������ �߰�\n");
		printf("2. ���� ������ �˻�\n");
		printf("3. ���� �� ������ ���\n");
		printf("4. ���� ������ ����\n");
		printf("5. ���α׷�â ����\n");
		printf("6. ���α׷� ����\n");

		scanf_s("%d", &playerInput);

		if (playerInput == 1) 
		{
			AddMonsterInfo(monsterGroup, &totalMonsterCount);
		}
		
		if (playerInput == 2)
		{
			SearchMosterByName(monsterGroup, totalMonsterCount);
		}

		if (playerInput == 3)
		{
			ShowAllMonsterData(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 4)
		{
			DeleteMonsterName(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 5)
		{
			system("cls");
		}

		if (playerInput == 6)
		{
			break;
		}

		
	}

	PrintMonsterList(monsterGroup, totalMonsterCount);

	return 0;
}