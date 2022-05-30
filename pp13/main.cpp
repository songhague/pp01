// PP13.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>//쉽게
#include<iostream>
#define DGW_NEW new(_NORMAL_BLOCK,_FILE_,_LINE_)



int main()
{
	std::cout << "Hellow Word";

	int* a = new int[6];
	/*Dumping objects ->
	{152} normal block at 0x000001E732B5D640, 24 bytes long.
		Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD 메모리 누스
		Object dump complete.*/
	_CrtDumpMemoryLeaks();//지정한 위치 쉽게
}