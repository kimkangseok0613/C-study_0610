// ���� �����
// printf scanf_s
// Ű������ �Է� ������� ���

#include "lectures.h"
#include "FileFunC.h"

#define filename2 "filemode.txt"

// ������ ����Ǵ� ��ġ.
// 
// printf : ����Ϳ� ����� �ϰ� �ֽ��ϴ�.
// scanf  : Ű����κ��� �Է¹��� ���� �ּҸ� �����ؼ� �ּҿ� ����
// fopen  : ������ ���ų� ���� ���ؼ� �ü���� �������ִ� �Լ�
// ������,������,�� - �ü���� ������ �ִ�.
// Ű����,���콺,����� ... �ϵ��� ��ǻ�Ϳ��� �۵��ϵ��� �������ش�.
// �ϵ��� ȸ�簡 ���� �پ��ϰ�,
// ��Ʈ�� : ����� <- Ű���� <- ���콺 , ���� �ٸ� �ϵ��� �������� ��
//
// ������ ���� -> RAM : �ֹ߼� �޸� : ��ǻ�� �Ǵ� ���α׷��� ����Ǹ� ������� �޸�
// ���ֹ߼� �޸� : ���α׷��� ����ǰ� ��ǻ�Ͱ� ����ǵ� ����Ǵ� �޸�
// �����͸� �����ϰ�ʹ�.
// �ü���� �ٸ���, ������ �� �ٸ� �����͸� �����Ϸ���, ���� ��Ʈ���� ���������� �Ѵ�.
// ����ü File

// ���� �����2
// ����. "w+" Appendix ����
// w+���
// ��� : ������ �а� ���� ���� ���. ������ �������� ������ ������ ���� �����ϰ�, ������ �����ϸ� ������ ��� ����� �ٽ� ���ϴ�.
//
// r+���
// ��� : ������ ���� �� ���� ���� ���. ������ �������� ������ ������ �߻��մϴ�.
// 
// a��� (appendix)
// ��� : ������ �߰� ���� ���� ���� ���. ������ �������� ���ο� �����͸� ���� ���� ����Դϴ�.
// 
// a+���
// ��� : ������ �߰��� �Ŀ� �б���� ������ ���.
// 
// fseek �Լ� : ������ ������� �� ������ ũ�⸸ŭ file pointer ����Ű�� ���� �޶����� �ȴ�.
// fp�� �̿��ؼ� ����� �б⸦ ���ÿ� �Ѵٸ�, ó���� ���⸦ fp ������ ���� ����Ű�� �ȴ�.
// fseek(fp,0,SEEK_SET);
// SEEK_SET : ������ ������
// SEEK_END : ������ ��
// SEEK_CUR : ������ ���� ������
//
// ���
// "w+" : ����/�б� ������ ���, ������ �����ϸ� ������ ��� ����� ���� ����
// "r+" : �б�/���� ������ ���, ������ ���� �Ŀ� �ٽ� ���Ⱑ ������ ���
// "a"	: ������ ����Ű�� ������ ����(EOF)���� �����͸� �߰��ϴ� ���
// "a+"	: ������ �߰��� �Ŀ� �б���� ������ ���

void WritePlus()
{
	FILE* fp = fopen(filename2, "w+");

	if (fp == NULL)
	{
		printf("���� ���� ����!\n");
	}
	// ���� �Է�(write)
	fputs("Hello World!!\n", fp);
	// ���ϰ� ������ �� '\0' 
	fseek(fp, 0, SEEK_SET);
	// ���� ���(read)
	char buffer[100];
	fgets(buffer, sizeof(buffer), fp);
	printf("Read from this file : %s", buffer);
	fclose(fp);
}

void FileIndicator()
{
	FILE* fp = fopen(filename2, "r");
	if (fp == NULL)
	{
		//ferror(fp);
		printf("���� �б� ����!\n");
	}

	fgetc(fp);	// File���� fp�� �ּҰ� ����Ű�� �ִ� char�� ������ ��, fp�� �����ּҸ� �����Ѷ�
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	printf("���� �����Ͱ� ����Ű�� �ִ� ���� : %c\n", fgetc(fp));
	fclose(fp);
}

void ReadPlus()
{
	FILE* fp = fopen(filename2, "r+");

	if (fp == NULL)
	{
		printf("���� ���� ����!\n");
	}
	char buffer[100];
	fgets(buffer, sizeof(buffer), fp);
	printf("Read from this file : %s", buffer);

	fseek(fp, 0, SEEK_END);
	fputs("Append text\n", fp);
	fclose(fp);
}

void AppendixMode()
{
	FILE* fp = fopen(filename2, "a");
	if (fp == NULL)
	{
		printf("append mode error!\n");
	}
	fputs("Append More Text\n", fp);
	fclose(fp);
}

void AppendixPlusMode()
{
	FILE* fp = fopen(filename2, "a+");
	if (fp == NULL)
	{
		perror("Append plus Error!\n");
	}
	fputs("Append even more Text\n", fp);
	fseek(fp, 0, SEEK_SET);

	char buffer[100];
	fgets(buffer, sizeof(buffer), fp);
	printf("Read from file %s\n", buffer);
	fclose(fp);
}

void lecture26()
{
	//WriteFile();	// ������ �Ἥ �����ϴ� �Լ�
	//ReadFile();		// ������ �д� �Լ�
	//WriteFileByStruct();
	//ReadFileByStruct();
	//WritePlus();
	//FileIndicator();
	//ReadPlus();
	//AppendixMode();
	AppendixPlusMode();

}
	// Test ���� �ȿ�, CProgram �̸����� ������ Today is 2024-07-31 �ؽ�Ʈ�� ��µǵ��� ������ �ϳ� �������ݴϴ�.
	// ������ ������ �о�ͼ� �ܼ����� ��µǵ��� ���ּ���.
	// Test\CProgram.txt �ִ� ���� Ȯ�����ֽð� �ܼ�â�� �����ְ� Today is 2024-07-31 ��µǵ��� �����غ�����.




