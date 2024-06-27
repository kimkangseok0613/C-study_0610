#include <stdio.h>
#include "CountNumFnc.h"

void StratNumberSetting();

int SetPlayerHP();

void InputPlayerValue();

void GameWin();
    {
    printf("맞추셨습니다. 축하합니다.\n");
    }   
	

int fail(int platerHP);

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
    if (BGColor > 15 || TextColor > 15) return;

    unsigned char ColorNum = (BGColor << 4) | TextColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}