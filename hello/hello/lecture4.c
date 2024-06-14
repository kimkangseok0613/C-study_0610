#include "lectures.h"

void lecture4()
{
	//이스케이프 문자
	int num = 500;
	printf("지금 보유한 금액 : 450원 \n");
	printf("\"지금 보유한 금액 : %d원\" \n", num);



	printf("지금 보유한 금액 : %d원 \n", num);
	printf("\a");
	printf("hello\b\b hi\n");
	printf("건냥하세요\r안녕\n");
	printf("반갑\t습니다.\n");
	printf("\\ \' \" \? 에러가 발생 하나요? \n");

	int num1;
	num1 = 10;

	int num2 = 20;

	int num3, num4, num5;
	num3 = 10, num4 = 20, num5 = 30;
	printf("%d %d %d ", num3, num4, num5);

	//입력
	//int width = 10, height = 12, length = 8;

	//int num;
	// 주석을 보고 함수를 사용 Scanf_s
	// 입력한 숫자를 "num의 들어간 숫자 : n" 형태로 출력하는 프로그램
	//printf("예제\n");
	//printf("숫자를 입력해주세요\n");
	//scanf_s("%d", &num);
	//printf("num에 들어간 숫자 : %d\n", num);

	// 변수의 이름 FirstNum1, FirstNum2, FirstNum3
	// 문제 1. " 두개의 정수를 입력 받아서 두 수의 뺄셈과 곱셈의 결과를 출력해보세요"
	// int FirstNum1, FirstNum2
	// 두 수의 뺄셈 : 결과
	// 두 수의 곱셈 : 결과
	//printf("문제1\n");
	//int Firstnum1, Firstnum2;
	//printf("첫번째 숫자를 입력해주세요 : ");
	//scanf_s("%d", &Firstnum1);
	//printf("두번째 숫자를 입력해주세요 : ");
	//scanf_s("%d", &Firstnum2);
	//printf("두 수의 뺄셈 : %d\n", Firstnum1 - Firstnum2);
	//printf("두 수의 곱셈 : %d\n", Firstnum1 * Firstnum2);

	// 문제 2. " 3개의 정수를 입력 받아서, Secondnum1 * Secondnum2 + Secondnum3 을 출력하는 코드를 만들어보세요"
	//printf("문제2\n");
	//int Secondnum1, Secondnum2, Secondnum3;
	//printf("첫번째 숫자를 입력해주세요 : ");
	//scanf_s("%d", &Secondnum1);
	//scanf_s("%d", &Secondnum2);
	//printf("세번째 숫자를 입력해주세요 : ");
	//scanf_s("%d", &Secondnum3);
	//printf("%d x %d + %d 의 값은 : %d", Secondnum1, Secondnum2, Secondnum3, Secondnum1 * Secondnum2 + Secondnum3);

	// 문제 3. "두 개의 정수를 입력받아서 몫과 나머지를 출력하는 코드를 작성해보세요.
	// 몫을 구하는 방식 : a / b(나눈 값에서 정수 부분이 몫
	// a % b = a를 b로 나눈 나머지 값
	printf("문제3\n");
	int divisionnum1, divisionnum2;
	printf("첫번째 숫자를 입력해주세요 : ");
	scanf_s("%d", &divisionnum1);
	printf("두번째 숫자를 입력해주세요 : ");
	scanf_s("%d", &divisionnum2);
	printf("%d 나누기 %d 의 몫 : %d\n", divisionnum1, divisionnum2, divisionnum1 / divisionnum2);
	printf("%d 나누기 %d 의 나머지 : %d", divisionnum1, divisionnum2, divisionnum1 % divisionnum2);

}