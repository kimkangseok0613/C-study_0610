#include <stdio.h>
#include "CountNumFnc.h"
#include "Windows.h"

// 함수이름 쉽게 변경하는법 : Ctrl + R + R

int InputNumber()
{
	int returnnumber;
	return scanf_s("%d", &returnnumber);
}

void StartGameSetting()   // StartGame();
{
	int playerHP = 7;   // 잘못된 내용이 있습니다.

	printf("★☆환영합니다☆★\n");
	printf("Plese Press Any Number\n");
}

void InputPlayerValue()
{

}

void GameWin()
{
	printf("게임에서 승리하셨습니다.\n");
}

int SetPlayerHP()
{
	int PlayerHP = 5;
	printf("환영합니다.\n");
	printf("숫자를 입력하면 게임을 시작합니다.\n");
}


int fail(int playerHP)
{
	int currentplayerHP = playerHP - 1;
	return currentplayerHP;
	printf("틀렸습니다. 플레이어의 값을 입력해주세요\n");
}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}