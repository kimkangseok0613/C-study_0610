#include "lectures.h"

void lecture3()
{
	int a = 5 + 3;
	a = 4 + 7;
	printf("%d \n", a);
	float b = 3.2f + 4.7f;
	printf("%f \n", b);

		// 문제 1-1
		// 변수의 이름 width, height, length 정수를 담을 수 있는 변수 선언
		// 12 10 8

		// 문제 1-2. 세 변을 곱한 값(부피) Volume 변수에 저장하세요

		// 문제 1-3. Volume / 165로 나누어 원하는 계산 값을 구한다. Printf 함수로 출력하세요.

	int width = 12;
	int height = 10;
	int length = 8;

	int Volume = width * height * length;
	Volume = (Volume + 164) / 165;

	float Volume_f = width * height * length;
	Volume_f = Volume_f / 165;

	printf("문제 3의 답 : %d \n", Volume);
	printf("문제 3의 답 : %f \n", Volume_f);

	// 문제 2-1 섭씨, 화씨
	// 화씨 = 9/5 *섭씨 + 32
	// 화씨가 실수로 표현될 수 있도록 변수를 선언해주세요.
	// 9/5의 값이 1이 아닌 1.8이 나와야 합니다.
	// 섭씨 1, 화씨 33.8

	float Celsius = 1;                                //섭씨
	float Fahrenheit = 9.0f / 5.0f * Celsius + 32;   //화씨



	printf("섭씨 to 화씨 : %.1f", Fahrenheit);
}