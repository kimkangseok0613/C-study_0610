/*
*	작성일	: 2024-07-23
*	작성자	: 김강석
*	학습목표	: 구조체
*/

#include "lectures.h"
#include <stdbool.h>

void changePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int AddValue);

void lecture24()
{
	// 플레이어의 위치를 출력하는 함수
	// playerX, playerY, isPlayerDead :: 플레이어의 좌표(x,y), 플레이어의 생존여부
	int playerX = 5, playerY = 5;
	bool isPlayerDead = false;
	// structure 자료구조
	struct Player {
		int playerX;
		int playerY;
		bool isPlayerDead;
	};

	// typedef 키워드를 사용하여 구조체 선언하기
	typedef struct Player2 {
		int playerX;
		int playerY;
		bool isPlayerDead;
	}Player2;
	
	typedef struct Item {
		int itemX;
		int itemY;
		
	}Item;

	struct Player p1;
	Player2 p2;
	Item item1;

	// 구조체의 멤버변수를 사용하는 방법 : (.)연산자
	p1.playerX = 5;
	p1.playerY = 5;
	p1.isPlayerDead = true;
	printf("p1구체 멤버 playerX : %d, playerY : %d, isPlayerDead : %d \n", p1.playerX, p1.playerY, p1.isPlayerDead);


	changePlayerInfo(&playerX, &playerY, &isPlayerDead, 3);

	printf("playerX : %d, playerY : %d, isPlayerDead : %d \n", playerX, playerY, isPlayerDead);

	// 플레이어가 갖는 공통 속성을 하나로 묶어서 표현할 수 없을까?
	// 주소. 데이터 타입 (4바이트) n개
	// 서로 다른 데이터 타입을 사용할 수 있는 하나의 타입을 만들수 있는 기능 -> 구조체

}


void changePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int AddValue)	// x,y의 좌표를 AddValue수치만큼 증가시키새요
{
	*playerX += AddValue;
	*playerY += AddValue;
	*isPlayerDead = !(*isPlayerDead); // !(*(isPlayerDead : 주소를 담고있는 변수) : 가리키는 값 false -> true
}