/*
*	작성자	: 김강석
*	작성일	: 2024-06-26
*	학습목표	: break, continue 에 대해서 알아보자
*/

/*
*	for 반복문, while 반복문
*	반복적인 내용을 간결하게 표현.
*	break, continue.. (반복문, 조건문 - 제어문) 제어해주는 방법
*	for, while, do while, switch 사용을 합니다.
*/

/*
*	break	 : 제어흐름에서 벗어나기 위해 사용합니다. break 선언되면 해당 제어문에서 빠져 나옵니다.
*	continue : 제어흐름을 유지한 상태로 해당 코드의 실행만 건너뛰는 기능을 합니다.
*/

#include "lectures.h"

void lecture13()
{
	for (int i = 0; i < 10; i++)
	{	
		// printf 10번 박복하는 코드를 for 반복문.
		// 0번부터!특정 숫자까지 반복해서 아래의 코드를 실행하는데.
		// 내가 원하는 목표값에 도달하면
		printf("HI! %d\n",i);
	
		if (i == 7)
		{
			printf("i가 7일때 출력됨\n");
			break;
		}
	}
	int index = 0;
	for (;;)	//무한 반복문, ctrl + c
	{
		index++;
		printf("Hi %d\n", index);
		if (index == 7)
		{
			printf("7이 출력되었습니다.\n");
			break;
		}
	}
	
	//
	int targetNum;		// 출력하고자 하는 목표 숫자(scanf_s)
	int counter = 0;	// 반복문에서 targetNum을 찾기 위한 변수
	scanf_s("%d", &targetNum);
	
	for (;;)
	{
		counter++;
		if (targetNum == counter)
		{
			printf("원하는 결과값이 출력되었습니다. %d\n", targetNum);
			break;
		}
	}
	//
	////while 반복문
	scanf_s("%d", &targetNum);
	int w_counter=0;
	while (1)
	{
		w_counter++;
		if (targetNum == w_counter)
		{
			printf("원하는 결과값이 출력되었습니다. %d\n", targetNum);
			break;
		}
	}
	
	// continue 사용 예시
	int w_num = 0;
	while (w_num < 100)
	{
		w_num++;
		if (w_num % 2 == 0)	// 2로 나눴을때 나머지가 0인것
		{
			printf("건너뛴 w_num의 값 : %d\n", w_num);
			continue;
		}
		printf("w_num의 값 : %d\n", w_num);
		
	}

	// 주사위를 굴린다. 주사위에 12개의 면이 있다 scanf_s 주사위의 눈을 조작.
	// 만약에 주사위가 짝수가 나온다면, 갖고 있는 돈의 소지금이 2배가 된다.
	// 만약에 주사위가 홀수가 나온다면, 갖고 있는 돈의 소지금이 0원이 된다.
	// 소지금이 0원이 된다면 프로그램을 종료한다.

	printf("주사위 예제 시작\n");

	printf("주사위의 숫자를 골라주세요(1 ~ 12)\n");
	int dicenum, gamemoney;
	scanf_s("%d", &dicenum);
	gamemoney = 1000;	// 기본 소지금 1000원

	while (1)
	{
		if (dicenum < 1 || dicenum >12)
		{
			printf("잘못된 주사위 크기를 입력했습니다.\n숫자를 다시 입력해주세요\n");
			scanf_s("%d", &dicenum);
		}
		else
		{
			// 짝수인지 홀수인지 판별하는 코드를 작성해야 한다. 1 ~ 12
			if (dicenum % 2 == 0)	// 짝수
			{
				gamemoney = gamemoney * 2;
				
				if (gamemoney > 5000)
				{
					printf("당신이 승리하셨습니다.\n현재 보유중인 금액 : %d\n", gamemoney);
					break;
				}
				else
				{
					printf("현재 보유중인 금액 : %d\n", gamemoney);
				}

			}
			else                    // 홀수
			{
				gamemoney = 0;
				printf("당신은 게임에서 졌습니다.\n현재 보유중인 금액 : %d\n", gamemoney);
				break;
			}

		}
	}



}