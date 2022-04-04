#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private :
		bool _isGameRunning;

	public:
		MGameLoop()
		{
			_isGameRunning = false;
		}
		~MGameLoop(){}


		void Run()
		{
			_isGameRunning = true;

			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		};
		void Stop()
		{
			_isGameRunning = false;
		}

	private :

		void Initialize()
		{
			SetCursorState(false);
		}

		void Input() 
		{
			if(GetAsyncKeyState(VK_SPACE) == 0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{
				
			}
			else
			{
				
			}

		}
		void Update() 
		{
			
		}
		void Render() 
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			//system("cls");
			cout << "Rendering....";
			chrono::duration<double> renderDuration = chrono::system_clock::now()- startRenderTimePoint;
			
			cout << "Rendering speed: " << renderDuration.count() << "sec" << endl;

			int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);

			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::microseconds(remainingFrameTime));

		}

		void Release() {}

	private : // 게임 사용함수
		void MoveCursor(short x, short y) 
		{
			COORD playerPosition = { x,y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);
		}
		
		void SetCursorState(bool visible)
		{
			CONSOLE_CURSOR_INFO consoleCursor;
			consoleCursor.bVisible = visible;
			consoleCursor.dwSize = 1;

			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursor);
		}

	};
}
/*if (isKeyPressed)
			{
				COORD playerPosition = { playerCoordX, playerCoordY };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);
				cout << "P";
				isKeyPressed = false;
			}*/