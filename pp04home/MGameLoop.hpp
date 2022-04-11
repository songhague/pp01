#pragma once
#include <chrono>
#include <thread>
#include "MConsoIUtill.hpp"
#include "Player.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;

		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;

		Player p;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();
			startRenderTimePoint = chrono::system_clock::now();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
				// 한바뀌 돌때 이 사이클이 나옴
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnpressed();
			}

		}
		void Update()
		{

		}
		void Render()
		{
			

			cRenderer.Clear();
		

			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("p");

			cRenderer.MoveCursor(10, 5);
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS:" + to_string(10./ renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));//0.05초
		}
	};
}