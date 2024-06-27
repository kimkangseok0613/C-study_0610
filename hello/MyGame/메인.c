#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	"CountNumFnc.h"

int main(void)
{
	// printf 함수와 scanf 함수를 사용해서 게임의 느낌을 만들어 보도록 합시다.

	// 플레이어를 ★☆ 환영하는 텍스트를 출력해주세요. ☆★

	// printf(숫자를 입력하면 게임이 시작합니다.)
	// scanf -> 입력을 받는다.. 커서가 멈춘상태로 대기하고 있다.

	// 정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고, 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요.

	srand(time(NULL));
	int ComputerValue = rand() % 100 + 1; // 1 ~ 100 랜덤한 숫자가 ComputerValue에 입력이 됩니다.
	int UserValue;
	int playerHP = 7;

	printf("★☆환영합니다☆★\n");
	printf("Plese Press Any Number\n");

	printf("게임 시작\n");

	printf(" 1부터 100 사이의 값을 고르시면 게임이 시작됩니다.\n");
	scanf_s("%d", &UserValue);
	printf("컴퓨터의 값은 %d 입니다.\n", ComputerValue);
	printf("유저의 값은 %d 입니다.\n", UserValue);

	while (1)
	{
		if (ComputerValue == UserValue) \
		{	
			// 함수화_1 : GameWin() 게임에서 승리를 구현하는 함수를 만들어보세요.

			GameWin();
			break;
		}
		else
		{
			if (playerHP <= 0)
			{
				printf("게임종료\n");
				break;
			}

			// 함수화_2 : 플레이어의 체력을 감소시키고 숫자를 다시 맞출 기회를 주는 코드를 함수화 하세요
			else
			{
				playerHP--;
				printf("틀렸습니다. 플레이어의 값을 입력해주세요\n");

				scanf_s("%d", &UserValue);
				printf("플레이어의 값은 %d 입니다.\n", UserValue);
			}
		}
	}
	// 플레이어의 값과 컴퓨터의 값이 같으면 축하합니다. 게임을 클리어하셨습니다.

	// 플레이어의 값과 컴퓨터의 값이 다르면 틀렸습니다. 다시 시도해보세요.
	
	// 다시 시도를 하려면 어떻게 해야 할까? -> 내일 강의

	return 0;
}