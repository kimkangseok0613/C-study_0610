/*
*	�ۼ���	: 2024-07-23
*	�ۼ���	: �谭��
*	�н���ǥ	: ����ü
*/

#include "lectures.h"
#include <stdbool.h>

void changePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int AddValue);

void lecture24()
{
	// �÷��̾��� ��ġ�� ����ϴ� �Լ�
	// playerX, playerY, isPlayerDead :: �÷��̾��� ��ǥ(x,y), �÷��̾��� ��������
	int playerX = 5, playerY = 5;
	bool isPlayerDead = false;
	// structure �ڷᱸ��
	struct Player {
		int playerX;
		int playerY;
		bool isPlayerDead;
	};

	// typedef Ű���带 ����Ͽ� ����ü �����ϱ�
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

	// ����ü�� ��������� ����ϴ� ��� : (.)������
	p1.playerX = 5;
	p1.playerY = 5;
	p1.isPlayerDead = true;
	printf("p1��ü ��� playerX : %d, playerY : %d, isPlayerDead : %d \n", p1.playerX, p1.playerY, p1.isPlayerDead);


	changePlayerInfo(&playerX, &playerY, &isPlayerDead, 3);

	printf("playerX : %d, playerY : %d, isPlayerDead : %d \n", playerX, playerY, isPlayerDead);

	// �÷��̾ ���� ���� �Ӽ��� �ϳ��� ��� ǥ���� �� ������?
	// �ּ�. ������ Ÿ�� (4����Ʈ) n��
	// ���� �ٸ� ������ Ÿ���� ����� �� �ִ� �ϳ��� Ÿ���� ����� �ִ� ��� -> ����ü

}


void changePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int AddValue)	// x,y�� ��ǥ�� AddValue��ġ��ŭ ������Ű����
{
	*playerX += AddValue;
	*playerY += AddValue;
	*isPlayerDead = !(*isPlayerDead); // !(*(isPlayerDead : �ּҸ� ����ִ� ����) : ����Ű�� �� false -> true
}