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
            ////100�ʰ� ������ �׳� ��������                                   �и�������
            //if (remainingFrameTime > 0)
            //    this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
        }          //:sleep_for �̰� �Ⱦ��� cpu�������� �� ���� cpu�� ��� ���� ���ִ°� renderduration

    //�෹�̼� ���� ������ ����Ʈ���� ������ ����Ʈ���� �ð��� ��¾� fps�� ���ض�
    };
}