#include <stdio.h> // printf, scanf 함수를 사용하기 위해서 필요하다.
#include "Console.h"
#include <stdbool.h>

int main()
{
	// 콘솔창에 게임의 맵의 크기를 만들어 줘야합니다.
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	// 캐릭터의 위치 (14, 28)

	// 플레이어의 총알 구현(Bullet)
	int x = 14, y = 28;	// 플레이어의 x, y좌표
	int bx = 0, by = 0;	// 총알의 x, y좌표
	bool bullet = false; // 현재 총알이 생성됮지 않았으면 false, 생성됐으면 true

	


	while (true) // 무한루프
	{
		Clear();
	
		if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을때
		{
			if (x < 1) x= 1;
			x--;
			
		}

		if (GetAsyncKeyState(VK_RIGHT) & 8001) // 왼쪽키를 눌렀을때
		{
			if (x > 27)x = 27;
			x++;
			
		}

		if (GetAsyncKeyState(VK_UP) & 8001) // 왼쪽키를 눌렀을때
		{
			
			if (y < 1)y = 1;
			y--;
			
		}

		if (GetAsyncKeyState(VK_DOWN) & 8001) // 왼쪽키를 눌렀을때
		{
			if (y > 28)y = 28;
			y++;
			
		}

	}

	GotoXY(x, y);
	printf("▲");

 	// 총알
	if (GetAsyncKeyState(VK_SPACE) & 8001)
	{
		if(!bullet)	//!bullet과 bullet == false 같은의미

		bx = x;
		by = y - 1;
		bullet = true;
	}
	if (bullet)
	{
		by--;
		GotoXY(bx, by);
		printf("↑");

		if (by < 1)	//총알이 화면 가장 위로 넘어갔을때 총알이 비활성화된다.
			bullet = false;

	}


	Sleep(100);	//숫자만큼 기다렸다가 다시 실행한다.

}
