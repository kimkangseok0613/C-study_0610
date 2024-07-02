/*
*	작성자	: 김강석
*	작성일	: 2024-07-02
*	학습목표	: 배열
*	- 목적	: 별피하기 게임에 별을 여러개 한번에 생성하고 싶다.
*/

/*
*	배열의 선언
*	
*	- 변수의 선언 (데이터형) (변수이름) - 값;
*	- 배열의 선언 (데이터형) (배열이름) [];
* 
*	- 배열을 선언하는 첫번째 방법
*	데이터형 배열이름[배열의 수]
*	- 배열을 선언하는 두번째 방법
*/

#include <stdio.h>
#include "lectures.h"
#include <stdbool.h>

void lecture16()
{
	//int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;	// 100, 1000, 10000

	// 배열 1
	int arr[10] = { 0 };

	// 배열 2
	int arr2[] = { 0, 1, 2, 3, 4, 5 };	// arr2 6개 arr2[6] ~ arr2[9] 존재안함

	// 배열 3
	int arr3[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < 10; i++)
	{
		printf("배열에 들어간 요소 출력 : %d\n",arr3[i]);
	}

	// ex, ey 10개 사용할 수 있게 만들어보자.
	// 배열로 만들어보세요

	int ex[10] = { 0 };
	int ey[10] = { 0 };
	bool enemy[10] = { false };

	for (int i = 0;i < 10;i++)
		printf("ex값 : %d, ey값 : %d, enemy값 : %d\n", ex[i], ey[i],enemy[i]);

}