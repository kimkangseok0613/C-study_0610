#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

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
	int DummyValue;

	printf("★☆환영합니다☆★\n");
	printf("Plese Press Any Number\n");
	scanf_s("%d", &DummyValue);
	printf("게임 시작\n");
	printf("\n");
	printf(" 1부터 100 사이의 값을 고르시면 게임이 시작됩니다.\n");
	scanf_s("%d", &UserValue);
	printf("컴퓨터의 값은 %d 입니다.\n", ComputerValue);
	printf("유저의 값은 %d 입니다.\n", UserValue);
    if (ComputerValue == UserValue) {
        printf("컴퓨터의 값과 일치합니다. 축하합니다.");
    }
    else
    {
        printf("다시 시도해보세요.");

        scanf_s("%d", &UserValue);
        printf("플레이어의 값은 %d 입니다.", UserValue);

        if (ComputerValue == UserValue)
        {
            printf("컴퓨터의 값과 일치합니다. 축하합니다.");
        }
        else
        {
            printf("다시 시도해보세요.");

            scanf_s("%d", &UserValue);
            printf("플레이어의 값은 %d 입니다.", UserValue);

            if (ComputerValue == UserValue)
            {
                printf("컴퓨터의 값과 일치합니다. 축하합니다.");
            }
            else
            {

            }
        }
    }
	// 플레이어의 값과 컴퓨터의 값이 같으면 축하합니다. 게임을 클리어하셨습니다.

	// 플레이어의 값과 컴퓨터의 값이 다르면 틀렸습니다. 다시 시도해보세요.
	
	// 다시 시도를 하려면 어떻게 해야 할까? -> 내일 강의

	return 0;
}