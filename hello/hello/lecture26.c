// ���� �����
// printf scanf_s
// Ű������ �Է� ������� ���

#include "lectures.h"

void lecture26()
{
	//fp = fopen_s(&fp, "a.txt", "w");
	FILE* fp = fopen("a.txt", "w");

	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Hello World!!\n", fp);
	fclose(fp);


}