// void�� ���� ���� (1) �Լ��� ��ȯ�� (2) void pointer
// Enum�� ���� ���� (1) Enum�� �� �ʿ��Ѱ�
//
// ������ ������ ���ϱ� ������ : �����ϱ�, �ܼ� ��庥ó [����ü, ���� ���� ���] 
// ����� ���� ���� : ���� ���� �޸��� ����
// �����ϴ� �κ�(����� ���� ������Ʈ ���ϱ�) : ���� ������ ���α׷�, ���� ���� ���α׷�, ��Ʈ����, ���� �޸��� ����
// ������ �κ�, ���װ� �߻�, ������ �ް� ���� �κ�. -> �����ؼ� ����.
//
// �Լ����� ��ȯ���� ����ΰ�...
// void : ����, ����ִ�. �Լ��� ��ȯ���� ���Ǹ� ��ȯ��(Return Type)�� ����.
// 
// Swap(int* a, int* b){int temp; temp, *a, *b} : a�� �����Ϳ� b�� �����͸� ��ȯ�Ѵ�.
// vois Swap : ���ڷ� �Ѱ��ִ� a��b�� ���� �������ְ� ����ȴ�.
// int Compare() : ������ return 0; Ʋ���� 1�� ��ȯ�ϵ��� �Ͽ� if���̶� ���� ����� �߽��ϴ�.
// c++, stdbool - True False ��ȯ�ؼ� ����� �ϰ� �ֽ��ϴ�.

#include "lectures.h"

int Add_one(int* a)
{
	*a = *a + 1;
}

// ��ȯ���� �����ϴ� ���� : �����Ϸ��� �� �ڵ带 ������ ũ�⸦ �̸� �������ִ� ���.
// int num
//
// void�� �޸� ������ �󸶳� ����Ǵ� �� �� ��� void�� ������ ������ �� �����ϴ�.
// void* ������ �޸� ������ �󸶳� ����ƴ��� �� �� �ֳ���?
// void* �ҿ����� �����Դϴ�. �� �Ҿ����ϴٰ� �ұ�?
// �޸� ������ �󸶳� �����ϴ��� ũ�⸦ �˷��ݴϴ�. + ����, �Ǽ�, ����ü
// 
// ����
// int*	: �޸� ������ 4����Ʈ Ȯ���ϰ�, 4����Ʈ ������ int�������� �����͸� �о�Ͷ�
// void*: �޸� ������ 8����Ʈ Ȯ���ߴµ�, � �������� �𸥴�. ������ �ִ�.
// void*�� ����ϴ� ������ �����ϱ�?
// IntSwap, DoubleSwap, FloatSwap ������ Ÿ�Ը� �ٸ� ������ �Լ����� ���̰� �ִ�.
// �� �Լ����� Ÿ���� �����ؼ� �����ִ� �Լ��� ����� �ϳ��� ǥ���Ҽ� ���� ������?
// Ÿ���� �������ִ� ��� -> void pointer

#define TYPEOFINT 1
#define TYPEOFDOUBLE 2
#define TYPEOFFLOAT 3

// define INT, DOUBLE, FLOAT
// �Ǽ��� �ѹ��� ǥ���ϴ� ��� : enum Ű���� �����ϰ� �ֽ��ϴ�.
//
// ������ ENUM ����ϴ� ����
// 1. �ڵ��� ������ ���� : ����� ǥ���ϴ� ������ �̸��� ��Ȯ�� � �������� �ҿ����ϴ�. enum���� ����� �̸����� �����ϴ� ������ �����. TYPE -> ��� 3��(Float, Int, Double)
// 2. ���ӽ����̽� ���� ���� : �Լ��� ���ڷ� enum type�� ����� �� �ִ�.
// 3. ���������� ��������. : ���ӽ����̽� ������ ���� ������ �Ǿ������Ƿ� ���׸� ã�� ����������.
// 4. Ÿ�� �������� ����� : ����� �����͸� ���� ������ �ʿ���� enum type�� �����ϸ� �ȴ�.

typedef enum TYPE {TYPE_Char, TYPE_Int, TYPE_Double, TYPE_Long_Int}TYPE;

void SwapValue(void* ptr1, void* ptr2, TYPE type)
{
	switch (type)
	{
		case TYPE_Char:
		{
			char temp;
			temp = *(char*)ptr1;
			*(char*)ptr1 = *(char*)ptr2;
			*(char*)ptr2 = temp;
			break;
		}
		case TYPE_Int:
		{
			int temp;
			temp = *(int*)ptr1;
			*(int*)ptr1 = *(int*)ptr2;
			*(int*)ptr2 = temp;
			break;
		}
		case TYPE_Double:
		{
			double temp;
			temp = *(double*)ptr1;
			*(double*)ptr1 = *(double*)ptr2;
			*(double*)ptr2 = temp;
			break;
		}
		default:
			printf("�ش��ϴ� Ÿ���� �����ϴ�.\n");
	}
}

void IntSwap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void DoubleSwap(double* a, double* b)
{
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void FloatSwap(float* a, float* b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void lecture27()
{
	// void �Լ��� �̷��� ����ϸ� �ȵ˴ϴ�.
	int num = 1;	// �����Ϸ��� �̸� �޸� ������ 4����Ʈ Ȯ���� �մϴ�. 2������ �ۼ� 0101 �����ͷκ��� ������ ����.
	// void some;	// �����Ϸ��� �޸� ������ �󸶳� �����ؾ��ϴ��� �˼��ֳ���?
	int num2 = Add_one(&num);
	printf("%d\n", num2);

	void* voidPtr; // ������ ������ 64��Ʈ �ý����϶� 8����Ʈ�� ũ�⸦ Ȯ���մϴ�.
	printf("void*�� ũ�� : %d\n", sizeof(voidPtr));

	double a = 1.1;
	voidPtr = &a;

	// voidPtr�� double* �������� Type ��ȯ�ϰڴ�.
	//*((double*)voidPtr) == *(double*)voidPtr

	printf("voidPtr�� ����Ű�� �� : %f\n", *(double*)voidPtr);


	char c1 = 'a';
	char c2 = 'b';
	SwapValue(&c1, &c2, TYPE_Char);
	printf("�� Ȯ�� %c %c\n", c1, c2);

	int a1 = 1;
	int a2 = 2;
	SwapValue(&a1, &a2, TYPE_Int);
	printf("�� Ȯ�� %d %d\n", a1, a2);

	double d1 = 1.1;
	double d2 = 2.2;
	SwapValue(&d1, &d2, TYPE_Double);
	printf("�� Ȯ�� %f %f\n", d1, d2);

}