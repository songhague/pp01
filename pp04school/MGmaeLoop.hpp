#pragma once
#include<chrono>
#include<thread>
#include "MConsolUtil.hpp"


using namespace std;

namespace MuSeoun_Engine
{
    class MGameLoop
    {

    private:
        bool _isGameRunning;
        ConsoleRenderer cRenderer;

    public:

        MGameLoop()
        {
            _isGameRunning = false;
        }
        ~MGameLoop()
        {

        }
        void Run() {
            _isGameRunning = true;
            Initialize();

            while (_isGameRunning)
            {
                Input();
                Update();
                Render();
            }
            Release();
        }
        void Stop() {
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
            if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
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
            chrono::system_clock::time_point startRender = chrono::system_clock::now();

            cRenderer.Clear();
            cRenderer.MoveCursor(10, 20);


            chrono::duration<double> fps = chrono::system_clock::now() - startRender;

            string fpz = "FPS(milliseconds):" + to_string(fps.count());
            cRenderer.DrawString(fpz);

            //cout << "Rendering speed:" << renderduration.count() << "sec" << endl;

            //int remainingFrameTime = 100 - (DWORD)(fps.count() * 1000.0);
            ////100초가 넘으면 그냥 지나가라                                   밀리세컨드
            //if (remainingFrameTime > 0)
            //    this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
        }          //:sleep_for 이거 안쓰면 cpu점유율은 다 먹음 cpu를 잠깐 쉬게 해주는것 renderduration

    //듀레이션 내가 시작한 포인트부터 끝나는 포인트까지 시간을 재는애 fps를 정해라
    };
}