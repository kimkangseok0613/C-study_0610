/*
*	�ۼ���	: 2024-07-15
*	�ۼ���	: �谭��
*	�н���ǥ	: �迭�� �������� ����-> "���"������ 
*/

// 1. �迭�� �������� ����
// (1) sizeof(�迭), sizeof(�����ͺ���) ������ ���� �ٸ��� ���´�.
// (2) �迭�� ��� �����ʹ�.

// 2. �����Ϳ� ���
// (1) ����� ����Ű�� ������ pointer to constant
// (2) ������ �� ��ü�� ��� constant pointer
// (3) ����� ����Ű�� �� ��ü�� ����� ��� constant pointer to constant

#include "lectures.h"

void ShowData(const int* Ptr) // const int* arr�� �ǹ̸� �����غ���
{
	const int* rPtr = Ptr;
	printf("%d \n", *rPtr);
	//*rPtr = 20;
}

void ShowAllData(int* const arr, int len)
{
	// for �ݺ������� arr�� ���� ��ŭ �迭��Ҹ� printf �Լ��� ��������

	int* const tempArr = arr;

	for (int i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}

}

void lecture19()
{
	const int s_num = 10;
	int* s_numPtr = &s_num;
	ShowData(s_numPtr);

	int s_arr[4] = { 1, 2, 3, 4 };
	int* s_arrPtr = s_arr;

	ShowAllData(s_arrPtr, sizeof(s_arr)/sizeof(int));

	// (1) sizeof ������
	int arr[3] = { 1, 2, 3 };
	int* arrPtr = arr;	// &arr[0] ǥ���� �� �ִ�.

	printf("�迭�� ũ�� : %d\n", sizeof(arr));		// sizeof(int) x 3 = 12
	printf("�������� ũ�� : %d\n", sizeof(arrPtr));	// 16����, 32��Ʈ, 64��Ʈ  8 x 4��Ʈ(32) 16 x 4��Ʈ(64)

	// �����ͷ� �ڵ带 �ۼ��ϴ°�, �Ǽ��� ������ ���ɼ��� �������� �����ϱ⵵ �����ϴ�.
	// 4000����Ʈ�� 8����Ʈ�� ǥ���Ҽ��� �ִ�.
	// ������ ���� ������� �ʴ� ���.

	// Constant (���)
	// Pi = 3.14
	// �ڵ��� �������� �����ִ� ������. �ڿ� ����Ǵ� ������ �ٲ� �� ����.
	//const int pi = 3.14
	//pi = 3.5;

	// (1) ����� ����Ű�� ������ pointer to constant
	// num�� ���� �������� ���ϰ� �����ش�.
	// const int# ������ ������ �� ���� �������� ���Ѵ�. ������ �����ڷ� ���� ���ٲ۴�.
	const int num = 10;
	//num = 15;
	const int* numPtr = &num;	// int const* numPtr = &num;
	//*numPtr = 15;
	
	// (2) ������ �� ��ü�� ��� constant pointer

	int num1 = 20;
	int num2 = 30;
	int* const numCPtr = &num1;	// ��� �������� ����. �迭�� ��� ������.
	*numCPtr = 40;
	//numCPtr = &num2;			// ��� ������. �ּҸ� �������� ���Ѵ�.
								// �迭�� ��� ������. �迭�� ���� ���� �迭�� �ּҸ� ������ �� ����.

	// (3) ����� ����Ű�� �� ��ü�� ����� ������ constant pointer to constant
	const int num3 = 40;
	const int num4 = 50;
	int* const numCPtr2 = &num3;
	//*numCPtr2 = &num4;

	// ����
	// ������. ����.
	// ���� - ��, �ּ�(&)
	// ������ - �ּ�, ��(*)

	// ������ ����
	// + Const
	// �� Const, �ּ� Const
	// �� Const - ��� ������					Constant Pointer
	// �ּ� Const - ����� ����Ű�� ������		Poiner to Constant
	// Const �����Ϳ� ����ϴ� ����?
	// ������ ������ ����� ������� �ʱ⸦ �����Ϸ� �ܰ迡�� �����ϱ� ���ؼ�(�������� �����ϱ� ���ؼ�)

	

}