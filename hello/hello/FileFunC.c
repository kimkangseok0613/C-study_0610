#include "FileFunC.h"

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
	fscanf_s(fp, "�̸� : %s, ���� : %d", People[0].name, 3, &People[0].age);
	printf("�̸� : %s, ���� : %d", People[0].name, People[0].age);
	fclose(fp);
}