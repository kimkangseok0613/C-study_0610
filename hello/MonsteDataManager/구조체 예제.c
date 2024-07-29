#include <stdio.h>
#include <string.h>

typedef int MyInt;
typedef int* MyIntPtr;

typedef struct Monster {
	char name[30];
	char region[30];
	char grade[30];
}Monster;


int Compare(char* str1, char* str2)	 // ��ȯ�ϴ� ���� 0�̸� �ٸ���. 1�̸� ����.
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;  // ������ 1�� ��ȯ�Ѵ�.

	return 0;
}

void SearchMonsterByname(Monster monster)
{
	char searchName[30];
	printf("�˻��ϰ� ���� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", searchName, 30);
	if (Compare(monster.name, searchName))
	{
		printf("�ش� �ϴ� ���͸� ã�ҽ��ϴ�.\n");
		printf(" ������ �̸� : %s, ������ ���� : %s, ������ ��� : %s", monster.name, monster.region, monster.grade);
	}
}

void ChangeMonsterInfo(Monster(*monster)[100], int* monsterIndexPtr)
{
	char newName[30];
	char region[30];
	char grade[30];
	printf("������ ���� �̸��� �Է����ּ��� : ");
	scanf_s("%s", newName, 30);
	printf("������ ���� ������ �Է����ּ��� : ");
	scanf_s("%s", region, 30);
	printf("������ ���� ����� �Է����ּ��� : ");
	scanf_s("%s", grade, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, newName);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);

	(*monsterIndexPtr)++;
}

void ShowMonsterInfo(Monster monster)
{
	printf("���� �̸� : %s\n", monster.name);
	printf("���� ��� : %s\n", monster.grade);
	printf("���� ���� : %s\n", monster.region);
}

//int main()
{
	MyInt myInt = 4;
	printf("%d\n", myInt);

	MyIntPtr myintPtr = &myInt;
	printf("%d\n", *myintPtr);

	Monster m1;
	strcpy_s(m1.name, 30, "���");

	printf("���� �̸� : %s\n", m1.name);

	// Compare �Լ�
	char name1[30] = "ȫ�浿";
	char name2[30] = "ȫ�浿";

	if (Compare(name1, name2)) {
		printf("����\n");
	}
	else {
		printf("�ٸ���\n");
	}

	// ����ü ������ ����
	// ����ü ������ �ּҿ����� ���� �ִ´�.
	Monster* monsterptr = &m1;

	Monster monsterGroup[100];

	int totalMonsterCount = 0;

	// ���߿� �ϸ� ���� �� 
	//int monsterSize;
	//scanf_s("%d", monsterSize);
	//Monster* monsterGptr = malloc(sizeof(Monster) * monsterSize);
	//free(monsterGptr);

	ChangeMonsterInfo(monsterGroup, &totalMonsterCount);

	printf("���� �̸� : %s, ���� ��� : %s, ���� ���� : %s", monsterGroup[0].name,
		monsterGroup[0].grade, monsterGroup[0].region);

	//ShowMonsterInfo(m1);
	//SearchMonsterByname(m1);
}