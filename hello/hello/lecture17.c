/*
*	�ۼ���	: 2024-07-11
*	�ۼ���	: �谭��
*	�н���ǥ	: �����Ϳ� ���� ����
*/

//	�������� ����
//	(������Ÿ��) * �̸�;

//	�����Ͷ�?
//	������ ����, ���ϴ� ��(�ּ�)�� ����

//	�޸� ���ϴ� ������ : �ּҿ����� &
//	���� : ������ ���� ����, &num
//	�ǹ� : num�� ������ �ִ� �ּҸ� ��ȯ�϶�.

//	�ּҸ� 16���� 8�� or 16�� ��Ʈ ������ ����ؼ� �޸� �ּ� ǥ��.
//	�ּҸ� ǥ���Ҷ� [16���� 4��Ʈ]
//	0xABCE0202 <- �ּ�. 32��Ʈ
//	0x 00000000 ABCE0202 <- 64��Ʈ

//	�޸��� �ּ� ����
//	int * numPointer; (���Ӹ� numPtr) ������ �̸�
//	������ ������ �����ϴ� ��.

#include "lectures.h"

void lecture17()
{
	int num;	// ������ ����
	scanf_s("%d", &num);
	printf("num�� �� ��� : %d\n", num);

	// �����Ϳ� ���ؼ� �ͼ�������.
	// ������ * ��ġ�� �������.
	int* numPtr = &num;	// int* numPtr �����ͺ��� ����� �ʱ�ȭ
	int* numPtr2 = &num;
	int* numPtr3 = &num;

	printf("%p\n", numPtr);
	printf("%p\n", numPtr2);
	printf("%p\n", numPtr3);

	printf("%d\n", *numPtr);
	printf("%d\n", *numPtr2);
	printf("%d\n", *numPtr3);

	// �����͸� ��� - 16���� �ּҰ� ��µȴ�.

	// �ּҿ� ����� ���� ����ϴ� ���.
	// ������ ������
	// '*' ���׿����� : ���ϱ�
	// ���׿����� : �̹� ����� ������ ���� �տ�, *numPtr
	// numPtr�� ����Ű�� �ִ°��� �����Ѵ�.
	// int sum = 2 * 4

	// �ǽ�> ���� int number 20�� �Ҵ����ּ���, ������ ������ ���� numberPtr �����ϰ�, number�� �ִ� �ּҸ� �Ҵ����ּ���.
	// printf�� ����ؼ� numberPtr�� �ִ� ���� ����غ��ø� �˴ϴ�.(* ������ ������ּ���)

	// ���� -> �� + �ּ�

	// 0. ���� ���� �� �ʱ�ȭ
	int number = 20;	// number �̸� 20 ��, number �ּ�
	// 1. ������ ������ �����ϴ� ��� : int*
	// 2. ������ �ּҸ� ��ȯ�ϴ� ������ �ּ� ������ &
	int* numberPtr = &number;
	// ������ ����
	// ������ ������ �� : �ּ�, �ּҰ� ����Ű�� �ִ� ������(����)
	printf("numberPtr �ּ� : %p\n", numberPtr);
	// 3. ������ ������ ����Ű�� �ִ� ������ ��ȯ�ϴ� ������ *
	printf("numberPtr ������ : %d\n", *numberPtr);

	// ������ �ּҰ� �����ϰ�
	// �ּҸ� �̿��ؼ� ���� �����ϴ� �۾�
	printf("���� number�� ��\n",number);
	*numberPtr = 30;
	printf("number�� �� : %d\n", number);

	// �ѹ� �� ����
	// 1. ���� num1 = 10;	������ Ư¡ : �޸� �ּҸ� ���� ���� �������ų� ������ �� �ִ�.
	// 2. �ּ� ������& : ������ �޸� �ּҸ� ���ϴ� �༮, &num1 : �����κ��� �ּҸ� ���� �� �ִ�. 0XABCD;
	// 3. ������ ������* : ������ ������ �����ϰ� �ִ�(�޸� �� ����Ű��) ���� ������ �� �ִ�. 

	// int * numPtr	: ������ ���� ����
	// *numPtr		: ������ ������ ���� ���� ȣ��, numPtr�� ������ ������.
	// *numPtr = 30;: �����Ͱ� ����Ű�� �ִ� ������ ���� �����Ѵ�. �����Ͱ� ����Ű�� �ִ� ������ ���� ���Ѵ�.

	int a_num = 10;
	int* a_numPtr = &a_num;
	int* b_numPtr = a_numPtr;

	(*a_numPtr)++;	// *a_numPtr = *a_numPtr + 1
	(*b_numPtr)++;	// *b_numPtr = *a_numPtr + 1
	printf("%d\n", a_num);

	// ���� ����
	int e_num1 = 10, e_num2 = 20;// ���� �̸� e_num1, e_num2 �����ؼ� 10, 20 �Ҵ����ּ���.
	int* e_num1Ptr = &e_num1;// e_num1, e_num2�� ����Ű�� ������ e_num1Ptr, e_num2Ptr�� ���� �� �������ּ���
	int* e_num2Ptr = &e_num2;
	// int* temp �����͸� �ϳ� ������ �ϰ�
	// temp�� e_num1Ptr ����, e_num2�� ->  e_num1, e_num2 -> temp �� �޾ƿ���
	// Swap ����
	printf("%d %d\n", *e_num1Ptr, *e_num2Ptr);	// ������ �� ���
	int* temp;
	temp = e_num1Ptr;
	e_num1Ptr = e_num2Ptr;
	e_num2Ptr = temp;

	printf("%d %d\n", *e_num1Ptr, *e_num2Ptr);	// ������ �� ���

	// ����
	printf("����\n");
	int exam_num1 = 10, exam_num2 = 20, temp_num;

	// num1, num2 �ٲ㼭 ����ϼ���.
	int* exam_num1Ptr = &exam_num1;
	int* exam_num2Ptr = &exam_num2;
	printf("%d %d\n", *exam_num1Ptr, *exam_num2Ptr);
	temp_num = exam_num1Ptr;
	exam_num1Ptr = exam_num2Ptr;
	exam_num2Ptr = temp_num;
	printf("%d %d\n", *exam_num1Ptr, *exam_num2Ptr);

}