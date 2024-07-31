// ���� �����
// printf scanf_s
// Ű������ �Է� ������� ���

#include "lectures.h"

#define filename "Test\\People.txt"

// ������ ����Ǵ� ��ġ.
// 

// printf : ����Ϳ� ����� �ϰ� �ֽ��ϴ�.
// scanf  : Ű����κ��� �Է¹��� ���� �ּҸ� �����ؼ� �ּҿ� ����
// fopen  : ������ ���ų� ���� ���ؼ� �ü���� �������ִ� �Լ�
// ������,������,�� - �ü���� ������ �ִ�.
// Ű����,���콺,����� ... �ϵ��� ��ǻ�Ϳ��� �۵��ϵ��� �������ش�.
// �ϵ��� ȸ�簡 ���� �پ��ϰ�,
// ��Ʈ�� : ����� <- Ű���� <- ���콺 , ���� �ٸ� �ϵ��� �������� ��
 
 
// ������ ���� -> RAM : �ֹ߼� �޸� : ��ǻ�� �Ǵ� ���α׷��� ����Ǹ� ������� �޸�
// ���ֹ߼� �޸� : ���α׷��� ����ǰ� ��ǻ�Ͱ� ����ǵ� ����Ǵ� �޸�
// �����͸� �����ϰ�ʹ�.
// �ü���� �ٸ���, ������ �� �ٸ� �����͸� �����Ϸ���, ���� ��Ʈ���� ���������� �Ѵ�.
// ����ü File

typedef struct Person {
	char name[30];
	int age;
}Person;

void WriteFile()
{
	// fp = fopen_s(&fp, "a.txt", "w");
	// fopen
	FILE* fp = fopen(filename, "w"); // a.txt ���ϰ� �ü�� ���� ��Ʈ���� ����

	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Today is 2024-07-31\n", fp); // fputs ( �Է��ϰ� ���� ��, ��Ʈ��);

	// FILE* ���� ��Ʈ���� �����ϴ� ����ü, stdout : ����Ϳ� �������ִ� ��Ʈ��
	//fputs("Hello World!!\n", stdout);

	fclose(fp);
}

void ReadFile()
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Read Error!\n");
		return 0;
	}

	// string, char
	//fgets : ���ڿ��� �о���� �Լ�
	//fgetc : �Ѱ��� �о���� �Լ�

	char buffer[100]; // ���� : �����͸� �Ͻ������� �����ߴٰ� �ʿ��Ҷ� ������ ���� �뵵

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}

void WriteFileByStruct()
{
	Person People[3] =
	{
		("�̼���", 31),
		("������", 32),
		("�庸��", 33)
	};

	for (int i = 0; i < 3; ++i)
	{
		printf("�̸� : %s, ���� : %d\n", People[i].name, People[i].age);
	}

	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		fprintf("�̸� : %s, ���� : %d\n", People[i].name, People[i].age);
	}
	fclose(fp);
}

void ReadFileByStruct()
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Read Error!\n");
		return 0;
	}

	Person People[3];
	for (int i = 0; i < 3; ++i)
	{
		fscanf_s(fp, "�̸� : %s, ���� : %d", People[i].name, 30, &People[i].age);
		printf("�̸� : %s, ���� : %d", People[i].name, People[i].age);
	}
}

void lecture26()
{
	//WriteFile();	������ �Ἥ �����ϴ� �Լ�
	//ReadFile();	������ �д� �Լ�
	WriteFileByStruct();
	//ReadFileByStruct();

	// Test ���� �ȿ�, CProgram �̸����� ������ Today is 2024-07-31 �ؽ�Ʈ�� ��µǵ��� ������ �ϳ� �������ݴϴ�.
	// ������ ������ �о�ͼ� �ܼ����� ��µǵ��� ���ּ���.
	// Test\CProgram.txt �ִ� ���� Ȯ�����ֽð� �ܼ�â�� �����ְ� Today is 2024-07-31 ��µǵ��� �����غ�����.

	
	
	

}



