#pragma once

#include <stdio.h>
#define filename "Test\\People.txt"

// ~~~.h : 함수의 원형을 선언합니다.

// (데이터타입) 1.void 2.(반환값 데이터형) <- int, double, char, char*, double*, struct people

// int 함수이름(); : 반환값이 int이고 함수이름에 해당하는 녀석이 존재합니다. 컴파일러한테

// 구조체 헤더파일에 가져올때 구조체도 본문 내용을 작성해야한다. 구조체의 내용물도 전부 작성해줘야한다.

typedef struct Person {
	char name[30];
	int age;
}Person;

void WriteFile();
void ReadFile();
void WriteFileByStruct();
void ReadFileByStruct();