#pragma once
#include <chrono>
#include <thread>
#include "MConsoIUtill.hpp"
#include "Player.hpp"
#include "Mon.hpp"

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
        Mon m;

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
            m.Monmove();


        }
        void Update()
        {
            if (p.x == m.x && p.y == m.y)
            {
                Stop();
            }

        }
        void Render()
        {

            cRenderer.Clear();


            cRenderer.MoveCursor(p.x, p.y);
            cRenderer.DrawString("P");

            cRenderer.MoveCursor(m.x, m.y);
            cRenderer.DrawString("M");

            cRenderer.MoveCursor(10, 20);
            renderDuration = chrono::system_clock::now() - startRenderTimePoint;
            chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

            string fps = "FPS : " + to_string(1.0 / renderDuration.count());
            cRenderer.DrawString(fps);

            this_thread::sleep_for(chrono::milliseconds(20));
        }


        ////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

        //int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
        //if (remainingFrameTime > 0)
        //   this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));

    };
}