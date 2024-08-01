#include "FileFunC.h"

void WriteFile()
{
	// fp = fopen_s(&fp, "a.txt", "w");
	// fopen
	FILE* fp = fopen(filename, "w"); // a.txt 파일과 운영체제 파일 스트림과 연결

	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Today is 2024-07-31\n", fp); // fputs ( 입력하고 싶은 값, 스트림);

	// FILE* 파일 스트림을 저장하는 구조체, stdout : 모니터에 연결해주는 스트림
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
	//fgets : 문자열로 읽어오는 함수
	//fgetc : 한개씩 읽어오는 함수

	char buffer[100]; // 버퍼 : 데이터를 일시적으로 보관했다가 필요할때 꺼내서 쓰는 용도

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}
void WriteFileByStruct()
{
	Person People[3] =
	{
		("이순신", 31),
		("강감찬", 32),
		("장보고", 33)
	};

	for (int i = 0; i < 3; ++i)
	{
		printf("이름 : %s, 나이 : %d\n", People[i].name, People[i].age);
	}

	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		fprintf("이름 : %s, 나이 : %d\n", People[i].name, People[i].age);
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
	fscanf_s(fp, "이름 : %s, 나이 : %d", People[0].name, 3, &People[0].age);
	printf("이름 : %s, 나이 : %d", People[0].name, People[0].age);
	fclose(fp);
}