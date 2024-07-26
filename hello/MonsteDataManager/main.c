#include <stdio.h>
#include <string.h>

typedef struct Monster {
	char name[30];
	char region[30];
	char grade[30];
	char level[30];
}Monster;

// 1. Monster name, region, grade, level 구조체 변수를 선언해서 printf 출력
// 2. 구조체 배열, 만들어보고 반복문으로 몬스터 배열 출력.
// 3. 배열에다가 구조체 배열 데이터를 넣는다.
// 4. char name[100][30] = Monster.name;
int AddMonster(char(*monster_region)[30], char(*monster_grade)[30], int level, int* totalCount, Monster* monsterPtr)
{

}
int SearchMoster();		// compare 함수를 만들어야 한다.
int ShowAllMonster();	// printf( 배열이 있는 모든 요소..)
int DeleteMonster();	// 특정 배열 요소 검색해서 데이터가 있으면 해당 데이터를 null, 0 변경

int main()
{
	int playerInput = 0;

	char monster_nmae[100][30];
	char monster_region[100][30];
	char monster_grade[100][30];
	int moster_level[100];

	int totalMonsterCount; // 몬스터 데이터에 몇번 Index에 저장되어 있는가

	while (1)
	{
		system("cls");
		// 1. 몬스터 데이터 추가
		printf("1. 몬스터 데이터 추가\n");
		// 2. 몬스터 데이터 보기
		// 3. 몬스터 데이터 삭제
		// 4. 프로그램 종료
		printf("4. 프로그램 종료\n");

		scanf_s("%d", &playerInput);

		if (playerInput == 4)
		{
			break;
		}
	}


}