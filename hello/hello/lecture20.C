/*
*	작성일	: 2024-07-16
*	작성자	: 김강석
*	학습목표
*	- 포인터의 인자를 함수에 사용한다.
*	- Call by Value와 Call by Reference에 대해서 이해한다.
*/

// 정리
// 변수 - 값, 주소. &주소연산자
// 포인터 변수 - 주소 저장. *역참조연산자
// 포인터 변수 더하기 빼기. sizeof(데이터)
// 배열이 상수 포인터 : 저장한 주소를 변경하지 못하게 하는것. Constant Pointer
// 상수를 가리키는 포인터 : 값을 변경하지 못한다. Pointer to Constant 

// 배열을 매개 변수로 쓰기 위한 포인터 변수

// 배열을 선언하는 법 : int arr[10]; 처음 선언할 때 크기까지 만들어 줘야합니다/
// int arr[?] = 대입하는 코드가 불가능하다.
// 배열은 상수포인터.
// int arr[2]
// arr = arr2;

// 값이 그 크기에 따라서 변한다.
// 시작할 때 값을 초기화해줘야 한다.

void AddArrayElement(int* arr, int len, int add)	// 배열 요소의 값을 n만큼 더하는 함수로 변경해보세요.
{
	for (int i = 0; i < len; i++)
	{
		arr[i] += add;
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Call by Value Vs Call by Reference
// 함수가 종료될 때 값을 반환한다.
// return;	 ==	그 시점에서 함수를 종료시키고 함수를 호출한 곳으로 돌아간다.
// return 0; ==	함수를 종료하는 시점에 0을 반환한다.	

// 반환값이 없는 경우 void
// 반환값이 있는 경우 : 반환하고 싶은 데이터형을 입력해주면 된다.

void Call_by_Value(int num)
{
	num = num + 10;
}

void Call_by_Reference(int* numPtr)
{
	*numPtr = *numPtr + 10;
}

#include "lectures.h"

void SquareByValue_20(int num)
{
	num = num * num;
	printf("함수 안에서 실행된 결과 : %d\n", num);
}

void SquareByRef_20(int* numPtr)
{
	*numPtr = *numPtr * *numPtr;
}

// 전역 변수, 지역 변수
// 지역 변수 : { } 안에 작성되는 변수, { } 스택이 종료될때 변수도 같이 소멸된다.
// 전역 변수 : 

int global_val_l20 = 30;

void DoublePointerCallByRef(int** ref)
{
	*ref = &global_val_l20;
}

void DecimalToBinaray(int num)	// 10 1010(2)
{
	int binaray[20] = {0};
	int pos = 0;

	while (1)
	{
		binaray[pos] = num % 2;
		num = num / 2;
		pos++;

		if (num == 0)
			break;
	}

	//binaray[pos];

	for (int i = pos - 1; i >= 0; --i)
	{
		printf("%d", binaray[i]);
	}
}

void lecture20()
{
	

	int arr[3] = { 0,1,2 };		// 5,6,7
	AddArrayElement(arr,3,5);	// 포인터를 배우기 전에는 왜 함수로 바꾸는 것을 안했을까..

	int a = 10;
	int num = a;
	int* numPtr = &num;

	Call_by_Value(num);
	printf("Call_by_Value num의 값 : %d\n", num);
	Call_by_Reference(numPtr);
	printf("Call_by_Reference num의 값 : %d\n", num);

	printf("예제 문제1\n");
	int b = 3;
	SquareByValue_20(b);	// 값이 변경되지 않는 것
	printf("b의 값 : %d\n",b);
	SquareByRef_20(&b);	// 값이 제곱으로 출력되게
	printf("b의 값 : %d\n",b);

	printf("이중 포인터\n");	// 포인터 (주소)변수 - 주소

	int p1 = 10;
	int p2 = 20;
	int* p1Ptr = &p1;
	int* p2Ptr = &p2;
	int* p3Ptr = NULL;

	p3Ptr = &global_val_l20;	// 이중 포인터 : 주소로 가리키고 있는 변수의 주소 = 0x11111

	DoublePointerCallByRef(&p1Ptr);
	printf("%d ", *p1Ptr);

	printf("예제 문제 3\n");
	// 10진수를 2진수로 변환해서 출력하는 함수

	int input;
	scanf_s("%d", &input);

	DecimalToBinaray(input);

	// 11을 2진수로 만드는 법
	// 11/2 = 5 + 1
	// 5/2	= 2 + 1
	// 2/2	= 1 + 0
	// 1/2	= 0 + 1
	// 1011(2) : 1+2+8 = 11
}