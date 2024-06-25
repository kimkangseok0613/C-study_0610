/*
*	숫자 맞추기 게임 도전사항
	전제 사항	: 조건문과 반복문으로 답 맞추기 구현
	도전 과제1	: 플레이어의 값이 컴퓨터값과 다르면 작으면 작다. 크면 크다라고 출력 되도록 작성
	도전 과제2	: 플레이어가 숫자를 맞출 수 있는 기회를 제공해서. 틀릴 때 마다 기회를 줄이는 코드.
*/
#include <stdio.h>

main(void) {
	srand(time(NULL));
	int ComputerValue = rand() % 100 + 1; // 1 ~ 100 랜덤한 숫자가 ComputerValue에 입력이 됩니다.
	int UserValue;
	int DummyValue;

	printf("★☆환영합니다☆★\n");
	printf("숫자를 입력하면 게임을 시작합니다\n");
	scanf_s("%d", &DummyValue);
	printf("게임 시작\n");
	printf("\n");
	printf(" 1부터 100 사이의 값을 고르시면 게임이 시작됩니다.\n");
	scanf_s("%d", &UserValue);

	for (int i = 5; i > 0; i--)
	{
		if (UserValue == ComputerValue)
		{
			printf("이겼습니다!\n");
		}
		else if (UserValue < ComputerValue)
		{
			printf("더 큰 숫자입니다. %d회 남았습니다.\n", i);
			scanf_s("%d", &UserValue);
		}
		else if (UserValue > ComputerValue)
		{
			printf("더 작은 숫자입니다. %d회 남았습니다.\n", i);
			scanf_s("%d", &UserValue);
		}

	}
}