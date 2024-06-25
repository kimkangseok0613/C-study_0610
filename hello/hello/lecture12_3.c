/*	
*	학습 목표 : while 반복문
* 
*	for 반복문 학습
*	while 반복문으로도 반복을 표현할 수 있다.
*/

/*
*	while(조건식)	:	조건식이 true면 루프 본체를 실행, false면 다음 코드를 실행.
*	{
*		코드 내용;		// 루프 본체
*		변화식;
*	}
*/

/*
*	do ~ while 
*	
*	do
*	{
*		반복시킬 코드;
*	} while (조건식);
*/

#include "lectures.h"

void lecture12_3()
{
	int i = 0;
	while (i < 10)		// i가 10보다 작으면 계속 반복해라
	{
		i = i + 2;		// 변화식
		printf("Hello World!\n");
	}

	int index;
	scanf_s("%d", &index);

	while (index != 3)			// while 조건식에 조건으로 대입연산자(=)를 사용하면 무한 루프에 빠질 수 있으므로 유의해야 한다.

	{
		printf("Hello World!\n");
		scanf_s("%d", &index);
	}

	// while 반복문의 장점. 몇 번 반복될지 모르는 코드에서 사용하기 쉽다.

	// do ~ while 예제
	// 한 번은 받으시 출력하도록 구현이 되어 있는 코드.
	int i_doNum = 4;
	do
	{
		printf("한 번은 반드시 출력하는 do ~ while문.\n");
		i_doNum = i_doNum * 3;
	} while (i_doNum < 10);

	// do ~ while 장점 : 반드시 한번은 실행해준다.
}