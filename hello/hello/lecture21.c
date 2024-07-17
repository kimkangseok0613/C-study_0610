/*
*	작성일	: 2024-07-17
*	작성자	: 김강석
*	학습목표	: 메모리 공간에 대한 이해, 동적 메모리 할당, 포인터 사용
*/

/*
*	코드		영역 : CPU가 읽어들인 파일을 실행시킨다. 명령어로 실행한다.
*	데이터	영역 : 전역변수, static 으로 선언한 변수가 저장된다.
*	힙		영역 : 메모리를 수동으로 해제해야 하는 저장 공간
*	스택		영역 : 메모리가 자동으로 해제되는 저장 공간
*/

// 1. 스택	영역 : 함수 호출 call by value. 정보를 표현할때 기존값은 유지한채로 다른 결과를 표시하고 싶을때
// 2. 힙		영역 : 배열의 크기에 대해서 고찰. 필요한 데이터 공간만큼 적재적소로 넣으면 베스트가 아닐까

// 스택, 힙 영역을 나누는 이유
// 메모리 공간이 한정적이기 때문이다.

// 오버플로우
// 힙 오버플로우		: 힙이 스택을 침범
// 스택 오버플로우	: 스택이 힙 공간을 침범

// 재귀 함수 : 함수가 자기자신을 호출하도록 한 후. 무한반복
// 힙 오버플로우 예시 : malloc, free 직접 메모리 할당 및 해제. 어떤 함수를 실행할 때마다 malloc 공간을 배정.

#include "lectures.h"

void AllocateArray(int count)
{
	// 메모리 할당 함수 사용해보기
	int *newPtr = malloc(sizeof(int) * count);

	for (int i = 0; i < count; ++i)
	{
		*(newPtr+i) = i+1;
		printf("%d\n", newPtr[i]);
	}
	free(newPtr);
}

void lecture21()
{
	// 동적으로 메모리를 할당하는 함수 malloc
	// memory + allocation : 메모리 할당 함수 줄여서 malloc
	// 포인터 변수 - malloc(크기); 크기 : 메모리 공간의 크기 

	int num1 = 20;
	int* numPtr = &num1;
	int* const numPtr2 = malloc(4);

	*numPtr2 = num1;
	printf("%d \n", *numPtr2);

	// 동적 할당한 메모리는 반드시 해제해줘야 합니다
	// free
	printf("%d\n", *numPtr2);
	free(numPtr2);

	int arr[4] = { 1,2,3,4 };
	int* numPtr3 = malloc(sizeof(int) * 4);	// 4 x 4 = 16
	numPtr3 = arr;

	printf("%d\n", *(numPtr3+0));
	

	printf("예제 문제\n");

	// 동적으로 정수형 포인터 크기를 생성하는 함수
	int* a_Ptr = NULL;
	int count;
	scanf_s("%d", &count);
	AllocateArray(count);
	

	// 게임을 만들때.. 숫자를 데이터로 사용하지만, TEXT를 많이 사용한다.

	char c = 69;	// 69에 대응되는 아스키 문자 하나가 출력
	char c2 = 'a';
	printf("%d\n", c2);
	printf("%c\n", c2);

	// H, e, l, l, o
	// 문자열(string)
	char* s = "Hello";
	printf("%s\n",s);

	// 리터럴 문자열 "@@@@@"
	// 컴파일 시에 0x00000 주소를 반환합니다.

	char sArr[5] = { 'H', 'e', 'l', 'l', 'o' };

	for (int i = 0; i < 5; ++i)
	{
		printf("%c\n", sArr[i]);
	}

	char* s2 = "Hello World";
	printf("%s \n", s2);

	//printf("%c", *(s2 + 1));

	// 대문자 W 출력 : 6
	//// d 출력 : 10
	//printf("%c %d", *(s2 + 10), *(s2 + 10));
	// 6번째에 있는 공백문자 출력 : 5
	//printf("%c %d", *(s2 + 5), *(s2 + 5)); // 띄어쓰기가 32번 아스키 코드로 등록되어있다.
	// d문자의 다음 요소 출력 : 11
	//printf("%c %d", *(s2 + 11), *(s2 + 11)); // 문자열의 마지막에는 \'0' = NULL 문자.
	// NULL 문자. 문자열의 마지막을 알려주기 위한 문자.
	printf("NULL문자를 이용해서 문자열 출력하기\n");
	int index = 0;

	while (*(s2 + index) != 0)	// 0이 되면조건문을 종료
	{
		printf("%c", *(s2 + index));
		index++;
	}

}