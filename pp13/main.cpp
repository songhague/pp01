// PP13.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>//����
#include<iostream>
#define DGW_NEW new(_NORMAL_BLOCK,_FILE_,_LINE_)



int main()
{
	std::cout << "Hellow Word";

	int* a = new int[6];
	/*Dumping objects ->
	{152} normal block at 0x000001E732B5D640, 24 bytes long.
		Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD �޸� ����
		Object dump complete.*/
	_CrtDumpMemoryLeaks();//������ ��ġ ����
}