#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "Player.hpp"
#include "ddongA.hpp"
#include "ddongB.hpp"
#include "ddongC.hpp"
#include "ddongD.hpp"
#include "ddongE.hpp"
#include "ddongF.hpp"
#include "ddongG.hpp"
#include "ddongH.hpp"

#pragma comment(lib, "OpenGL32")

using namespace std;

static GLuint texName[2];

namespace Ddong
{
    static GLuint texName[2];//static 키워드 정적인지 동적인지를 알려준다. 자료형이 아님
    class DGameLoop
    {
        GLFWwindow* window;
        bool GameStart = false;

        float ratio;
        int width, height;

        Player p;
        DdongA a;
        DdongB b;
        DdongC c;
        DdongD d;
        DdongE e;
        DdongF f;
        DdongG g;
        DdongH h;

        bool stop; //충돌체크

        static void error_callback(int error, const char* description)
        {
            fputs(description, stderr);
        }
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
        }
        typedef struct tagBITMAPHEADER {
            BITMAPFILEHEADER bf;
            BITMAPINFOHEADER bi;
            RGBQUAD hRGB[256];
        }BITMAPHEADER;

        BYTE* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* imgSize, const char* filename)
        {
            FILE* fp = fopen(filename, "rb");	//파일을 이진읽기모드로 열기
            if (fp == NULL)
            {
                printf("파일로딩에 실패했습니다.\n");	//fopen에 실패하면 NULL값을 리턴
                return NULL;
            }
            else
            {
                fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//비트맵파일헤더 읽기
                fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//비트맵인포헤더 읽기
                fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//색상팔렛트 읽기

                int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//이미지 사이즈 계산
                *imgSize = imgSizeTemp;	// 이미지 사이즈를 상위 변수에 할당

                BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp);	//이미지크기만큼 메모리할당
                fread(image, sizeof(BYTE), imgSizeTemp, fp);//이미지 크기만큼 파일에서 읽어오기
                fclose(fp);

                return image;
            }
        }
        void init(void)
        {
            glClearColor(0.3f, 0.3f, 0.3f, 1);

            BITMAPHEADER originalHeader;	//비트맵의 헤더부분을 파일에서 읽어 저장할 구조체
            int imgSize;			//이미지의 크기를 저장할 변수
            BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, "ddonge.bmp");
            BYTE* image1 = LoadBitmapFile(&originalHeader, &imgSize, "persong.bmp"); //비트맵파일을 읽어 화소정보를 저장
            if (image == NULL) return;        //파일 읽기에 실패하면 프로그램 종료

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

            glGenTextures(2, texName);
            glBindTexture(GL_TEXTURE_2D, texName[0]);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                GL_NEAREST);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 640, 640, 0, GL_ALPHA, GL_BYTE, image);

            glBindTexture(GL_TEXTURE_2D, texName[1]);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                GL_NEAREST);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 640, 640, 0, GL_ALPHA, GL_BYTE, image1);
        }
    private:
        void Input()
        {
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
            {
                p.isKeyright();
            }
            if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
            {
                p.isKeyleft();
            }
        }
        void Update()
        {
            a.speed();
            b.speed();
            c.speed();
            d.speed();
            e.speed();
            f.speed();
            g.speed();
            h.speed();

            //충돌 시
            if (p.x >= a.dx && p.x <= a.dxx)
            {
                if (p.y + 0.1f >= a.dy && p.y + 0.1f <= a.dyy)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= a.dy && p.y <= a.dyy)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= a.dx && p.x + 0.1f <= a.dxx)
            {
                if (p.y + 0.1f >= a.dy && p.y + 0.1f <= a.dyy)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= a.dy && p.y <= a.dyy)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= b.dx1 && p.x <= b.dxx1)
            {
                if (p.y + 0.1f >= b.dy1 && p.y + 0.1f <= b.dyy1)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= b.dy1 && p.y <= b.dyy1)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= b.dx1 && p.x + 0.1f <= b.dxx1)
            {
                if (p.y + 0.1f >= b.dy1 && p.y + 0.1f <= b.dyy1)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= b.dy1 && p.y <= b.dyy1)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= c.dx2 && p.x <= c.dxx2)
            {
                if (p.y + 0.1f >= c.dy2 && p.y + 0.1f <= c.dyy2)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= c.dy2 && p.y <= c.dyy2)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= c.dx2 && p.x + 0.1f <= c.dxx2)
            {
                if (p.y + 0.1f >= c.dy2 && p.y + 0.1f <= c.dyy2)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= c.dy2 && p.y <= c.dyy2)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= d.dx3 && p.x <= d.dxx3)
            {
                if (p.y + 0.1f >= d.dy3 && p.y + 0.1f <= d.dyy3)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= d.dy3 && p.y <= d.dyy3)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= d.dx3 && p.x + 0.1f <= d.dxx3)
            {
                if (p.y + 0.1f >= d.dy3 && p.y + 0.1f <= d.dyy3)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= d.dy3 && p.y <= d.dyy3)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= e.dx4 && p.x <= e.dxx4)
            {
                if (p.y + 0.1f >= e.dy4 && p.y + 0.1f <= e.dyy4)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= e.dy4 && p.y <= e.dyy4)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= e.dx4 && p.x + 0.1f <= e.dxx4)
            {
                if (p.y + 0.1f >= e.dy4 && p.y + 0.1f <= e.dyy4)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= e.dy4 && p.y <= e.dyy4)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= f.dx5 && p.x <= f.dxx5)
            {
                if (p.y + 0.1f >= f.dy5 && p.y + 0.1f <= f.dyy5)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= f.dy5 && p.y <= f.dyy5)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= f.dx5 && p.x + 0.1f <= f.dxx5)
            {
                if (p.y + 0.1f >= f.dy5 && p.y + 0.1f <= f.dyy5)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= f.dy5 && p.y <= f.dyy5)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= g.dx6 && p.x <= g.dxx6)
            {
                if (p.y + 0.1f >= g.dy6 && p.y + 0.1f <= g.dyy6)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= g.dy6 && p.y <= g.dyy6)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= g.dx6 && p.x + 0.1f <= g.dxx6)
            {
                if (p.y + 0.1f >= g.dy6 && p.y + 0.1f <= g.dyy6)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= g.dy6 && p.y <= g.dyy6)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x >= h.dx7 && p.x <= h.dxx7)
            {
                if (p.y + 0.1f >= h.dy7 && p.y + 0.1f <= h.dyy7)
                {
                    cout << "1충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= h.dy7 && p.y <= h.dyy7)
                {
                    cout << "3충돌\n";//꼭지점
                    Stop();
                }
            }
            if (p.x + 0.1f >= h.dx7 && p.x + 0.1f <= h.dxx7)
            {
                if (p.y + 0.1f >= h.dy7 && p.y + 0.1f <= h.dyy7)
                {
                    cout << "2충돌\n";//꼭지점
                    Stop();
                }
                if (p.y >= h.dy7 && p.y <= h.dyy7)
                {
                    cout << "4충돌\n";//꼭지점
                    Stop();
                }
            }
        }

        void Render()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[1]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(p.x, p.y);
            glTexCoord2f(1.0, 0.0); glVertex2f(p.x + 0.1f, p.y);
            glTexCoord2f(1.0, 1.0); glVertex2f(p.x + 0.1f, p.y + 0.1f);
            glTexCoord2f(0.0, 1.0); glVertex2f(p.x, p.y + 0.1f);
            glEnd();

            a.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(a.dx, a.dy);
            glTexCoord2f(1.0, 0.0); glVertex2f(a.dxx, a.dy);
            glTexCoord2f(1.0, 1.0); glVertex2f(a.dxx, a.dyy);
            glTexCoord2f(0.0, 1.0); glVertex2f(a.dx, a.dyy);
            glEnd();

            b.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(b.dx1, b.dy1);
            glTexCoord2f(1.0, 0.0); glVertex2f(b.dxx1, b.dy1);
            glTexCoord2f(1.0, 1.0); glVertex2f(b.dxx1, b.dyy1);
            glTexCoord2f(0.0, 1.0); glVertex2f(b.dx1, b.dyy1);
            glEnd();

            c.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(c.dx2, c.dy2);
            glTexCoord2f(1.0, 0.0); glVertex2f(c.dxx2, c.dy2);
            glTexCoord2f(1.0, 1.0); glVertex2f(c.dxx2, c.dyy2);
            glTexCoord2f(0.0, 1.0); glVertex2f(c.dx2, c.dyy2);
            glEnd();

            d.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(d.dx3, d.dy3);
            glTexCoord2f(1.0, 0.0); glVertex2f(d.dxx3, d.dy3);
            glTexCoord2f(1.0, 1.0); glVertex2f(d.dxx3, d.dyy3);
            glTexCoord2f(0.0, 1.0); glVertex2f(d.dx3, d.dyy3);
            glEnd();

            e.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(e.dx4, e.dy4);
            glTexCoord2f(1.0, 0.0); glVertex2f(e.dxx4, e.dy4);
            glTexCoord2f(1.0, 1.0); glVertex2f(e.dxx4, e.dyy4);
            glTexCoord2f(0.0, 1.0); glVertex2f(e.dx4, e.dyy4);
            glEnd();

            f.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(f.dx5, f.dy5);
            glTexCoord2f(1.0, 0.0); glVertex2f(f.dxx5, f.dy5);
            glTexCoord2f(1.0, 1.0); glVertex2f(f.dxx5, f.dyy5);
            glTexCoord2f(0.0, 1.0); glVertex2f(f.dx5, f.dyy5);
            glEnd();

            g.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(g.dx6, g.dy6);
            glTexCoord2f(1.0, 0.0); glVertex2f(g.dxx6, g.dy6);
            glTexCoord2f(1.0, 1.0); glVertex2f(g.dxx6, g.dyy6);
            glTexCoord2f(0.0, 1.0); glVertex2f(g.dx6, g.dyy6);
            glEnd();

            h.draw();
            glEnable(GL_TEXTURE_2D);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            glBindTexture(GL_TEXTURE_2D, texName[0]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(h.dx7, h.dy7);
            glTexCoord2f(1.0, 0.0); glVertex2f(h.dxx7, h.dy7);
            glTexCoord2f(1.0, 1.0); glVertex2f(h.dxx7, h.dyy7);
            glTexCoord2f(0.0, 1.0); glVertex2f(h.dx7, h.dyy7);
            glEnd();
            glFlush();

            glDisable(GL_TEXTURE_2D);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    public:
        DGameLoop() { stop = false; }
        ~DGameLoop() {}

        void Run()
        {
            std::cout << " SPACEVAR를 누르면" << endl;
            std::cout << " 게임 시작!!!" << endl;
            while (!GameStart)
            {
                if (GetAsyncKeyState(VK_SPACE) & 0x8000)
                {
                    GameStart = true;
                }
            }

            glfwSetErrorCallback(error_callback);
            if (!glfwInit())
                exit(EXIT_FAILURE);
            window = glfwCreateWindow(1000, 800, "Simple example", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            glfwMakeContextCurrent(window);
            glfwSetKeyCallback(window, key_callback);

            stop = true;
            init();
            while (!glfwWindowShouldClose(window))
            {
                if (stop == false)
                {
                    break;
                }
                glfwGetFramebufferSize(window, &width, &height);
                ratio = width / (float)height;

                Input();
                Update();
                Render();
            }
            glfwDestroyWindow(window);
            glfwTerminate();
            _CrtDumpMemoryLeaks();
            exit(EXIT_SUCCESS);
        }
        void Stop()
        {
            stop = false;
            std::cout << " Game over " << endl;
        }
    };
}