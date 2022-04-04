#pragma once//한번 빌드 한애는 무시해라
#include <iostream>
#include <String>
#include <Windows.h>

using namespace std;

namespace MuSeoun_Engine
{
    class ConsoleRenderer
    {
    public :
        ConsoleRenderer() { SetCursorState(false); }//생성자
        ~ConsoleRenderer() {}//소멸자

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