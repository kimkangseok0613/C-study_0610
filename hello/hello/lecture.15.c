/*
*	작성자	: 김강석
*	작성일	: 2024-06-28
*	학습목표	: 지역 변수와 전역 변수의 이해
*/

/*
*	지역 변수 (Local Varialble) : 중괄호 내부에서 생성되는 변수
*/

// 변수의 존재기간	: 중괄호가 끝날 때 변수가 사라진다. 지역 변수가 저장되는 공간(메모리 공간)을 스택(Stack)이라고 한다.

// 변수의 접근 범위	: 범위 밖에서 선언된 변수와 범위 안에서 선언된 변수의 이름이 같을때 어떤 변수를 사용할까?

// 같은 지역 내에서 같은 이름의 변수를 선언할 수 없다. - 컴팡일러가 같은 이름의 변수에 대해서 어떤 변수를 사용해야 할지 모르기 때문에

// 범위가 다른 곳에서 같은 이름의 변수가 선언되었다면, 가장 가까운 범위의 변수를 사용한다.

/*
*	전역변수(Global Variable) : 중괄호{ } 밖에 선언된 변수
*/

int count; //전역 변수의  선언. 전역변수는 선언시에 0으로 초기화 된다.

#include "lectures.h"

int PlusOne(int a, int b)
{
	a++;
	b++;
}

int SimpleFunc()
{
	count++;
	int num = 10;
	num++;

	return num;
}


void lecture15()
{
	int num = 17;
	// num의 값은 17

	count = 10;
	printf("count에 값 : %d\n", count);

	SimpleFunc();
	printf("num에 값 : %d\n", num);
	printf("count에 값 : %d\n", count);

	int count1 = 4, count2 = 6;
	PlusOne(count1, count2);
	printf("count1의 값 : %d, count2의 값: %d", count1, count2);
}
