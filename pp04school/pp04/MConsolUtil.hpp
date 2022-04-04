#pragma once//�ѹ� ���� �Ѿִ� �����ض�
#include <iostream>
#include <String>
#include <Windows.h>

using namespace std;

namespace MuSeoun_Engine
{
    class ConsoleRenderer
    {
    public :
        ConsoleRenderer() { SetCursorState(false); }//������
        ~ConsoleRenderer() {}//�Ҹ���

        void MoveCursor(short x, short y)
        {
            COORD playerPosition = { x,y };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);
        }

        void SetCursorState(bool visible)
        {

            CONSOLE_CURSOR_INFO consoleCursorinfo;
            consoleCursorinfo.bVisible = visible;
            consoleCursorinfo.dwSize = 1;

            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorinfo);
        }
        
        void DrawString(string s)
        {
            cout << s;
        }

        void Clear()
        {
            system("cls");
        }
    };
}