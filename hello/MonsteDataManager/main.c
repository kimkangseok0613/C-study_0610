#include <stdio.h>
#include <string.h>
#include "Function.h"
#define filename "MonsterData.txt"

// 1. Monster name, region, grade, level 구조체 변수를 선언해서 printf 출력
// 2. 구조체 배열, 만들어보고 반복문으로 몬스터 배열 출력.
// 3. 배열에다가 구조체 배열 데이터를 넣는다.
// 4. char name[100][30] = Monster.name;
//
// 함수를 만드는 프로그래밍
// 반환값 함수이름() {}
// Call by Value VS Call by Reference

void ShowAllMonsterData(Monster monster[100], int* total)
{
	for (int i = 0; i < *total; ++i)
	{
		printf(" 몬스터 %d번째의 이름 : %s, 지역 : %s, 등급 : %s\n", i+1, monster[i].name, monster[i].region, monster[i].grade);
	}
}

void SearchMosterByName(Monster monster[100], int totalMonsterCount)
{
	char searchName[30];
	printf("검색하고 싶은 이름을 입력하세요 : ");
	scanf_s("%s", searchName, 30);	// 동적할당, 프로그램 실행 뒤에 검색하고 싶은 다어를 searchName 공간에 저장.

	for (int i = 0; i < totalMonsterCount; ++i)
	{
		if (Compare(searchName, monster[i].name))
		{
			printf("해당 하는 몬스터를 찾았습니다.\n");
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
		perror("파일 쓰기 실패!\n");
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
		perror("파일 읽기 실패!\n");
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}

	fseek(fp, 0, SEEK_SET);	 // fp가 가리키는 주소를 파일의 시작으로 이동

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

	int totalMonsterCount = 0; // 몬스터 데이터에 몇번 Index에 저장되어 있는가

	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		
		// 1. 몬스터 데이터 추가
		// 2. 몬스터 데이터 보기
		// 3. 몬스터 데이터 삭제
		// 4. 프로그램 종료
		printf("1. 몬스터 데이터 추가\n");
		printf("2. 몬스터 데이터 검색\n");
		printf("3. 몬스터 총 데이터 출력\n");
		printf("4. 몬스터 데이터 삭제\n");
		printf("5. 프로그램창 정리\n");
		printf("6. 프로그램 종료\n");

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