/*	작성자	: 김강석
	작성일	: 2024-06-17
	학습목표	: 디버깅

	디버깅
	- 디버깅을 해야 하는 이유
	- 프로그래밍을 하면서 작성한 논리적인 문제를 해결하기 위해서
	- 문제가 의심가는 부분에 코드의 중단점을 생성하고 실제로 컴퓨터의 계산결과를 눈으로 확인할 수 있디.
	- 문제를 해결하기 위한 방법이다.(With Computer Debuging System)
	단축키
*/

// Operator 연산자
// 대입, 산술 연산자
// '=', -, +, /, %
// "=" : A = b 같다.(논리 연산자 - 수학) (대입 연산자);
// int num = 30;	//Left Value = Right Value : 오른쪽 값을 왼쪽 변수에 넣어주는 기능
// 결합 순서가 (a <- b) 정해져있다.

/*	복합 대입 연산자
	종류  :	a = a + b;	a += b;
			a = a - b;	a -= b;
			a = a * b;	a *= b;
			a = a >> b;	a >>= b;
			a = a & b;	a &= b;
			a = a | b;	a |= b;
*/

/*	증가, 감소 연산자
	num++;
	++num;
	num--
	--num;
	++ : 변수 +=1과 같은 뜻
	-- : 변수 -=1과 같은 뜻

	전위 증가 : 변수에 1을 먼저 더해준 후, 문장의 연산을 진행한다.
	후위 증가 : 문장의 연산을 먼저 진행 후 변수의 값을 변화 시킨다.
*/

/*	관계 연산자
*	비교 연산자. 두개의 값을 비교하여 그 관계를 표현하는 연산자.
*	a, b, result;
*	a = 10, b = 12
*	결과 값이 True(참), 거짓(False)으로 나옵니다.
*	True : 1, False : 0
*	result = (a>b);
*	result의 값이 True면 1이, False면 0이 들어간다.
*/

/*	논리 연산자
*	AND, OR, NOT
*	AND : && (Shift + 7)	-> A와 B가 모두 참이면 결과를 참인 결과를 반환한다. "1"
*	OR : ||(Shift + \(달러)) -> A와 B중 하나라도 참이면 1인 결과를 반환한다.
*	NOT : !변수				-> A가 True면 False 반환, A가 False면 True를 반환한다.
*/


#include "lectures.h";

void lecture6() {

	printf("디버깅 예제 문제\n");
	char a, b, c;
	a = 100;
	b = 300;
	c = a + b;
	printf("%d + %d = %d\n", a, b, c);

	printf("연산자 예제 문제\n");

	// 9 + 2 = 11, 9 - 2 = 7;

	int num1, num2, num3, result;
	result = 0;
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("계산 결과(L-Value) = %d x %d + %d = %d", num1, num2, num3, num1 * num2 + num3);
	printf("복합대입연산자(결과 %d += %d)\n", result, num1);


	printf("증가, 감소 연산자 예제 문제\n");
	int plusA = 10;
	int plusB = (plusA++) + 2;
	printf("plusB의 값은 무엇이 나올까요? : %d\n", plusB);
	printf("plusA의 값은 무엇이 나올까요? : %d\n", plusA);

	printf(" 결과값 = (%d)\n",num1 < num3);

	printf("연산자 우선 수위 마지막 예제\n");

	//문제 : 변수 A의 값은 3 + 4 x 5 이며, 변 수B의 값은 7 / 3 % 2 이다.
	//변수 A와 B의 값을 비교한 값을 Result 변수에 대입하여 출력해 보세요.

	int variableA;	// 3 + 4 * 5
	int variableB;	// 7 / 3 % 2
	int Final;		//variableA와 variableB를 관계연사자를 사용하여 Final에 대입해보세요.

	variableA = (3 + 4) * 5;
	variableB = ( 7 / 3 ) % 2;
	printf("변수A의 값 : %d\n", variableA);
	printf("변수B의 값 : %d\n", variableB);

	printf("결과값 = (%d)\n", variableA < variableB);

}