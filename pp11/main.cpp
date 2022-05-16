#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    float y = 0;
    float x = 0;

    float s = -0.7;
    float z = -0.5;
    float a = 0.3;
    float d = 0.1;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;

        int width, height;

        glfwGetFramebufferSize(window, &width, &height);

        ratio = width / (float)height;


        glClearColor(0.3f, 0.3f, 0.3f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);//나는 섞는다. 알파 블랜딩 하는조건 물체가 겹처있거나 투명한거 뒤에 있을때
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            x = x + 0.0001f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            x = x - 0.0001f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            y = y + 0.0001f;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            y = y - 0.0001f;
        }

        if (y <= z)
        {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.1f, 0.1f);
            glVertex2f(-0.1f, 0.1f);
            glVertex2f(0.1f, -0.1f);
            glVertex2f(-0.1f, -0.1f);
            glVertex2f(0.1f, -0.1f);
            glVertex2f(-0.1f, 0.1f);
            glEnd();
            cout << "이대환 생성!!!\n";
        }

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(z, a);
        glVertex2f(z, d);
        glVertex2f(s, d);
        glVertex2f(z, a);
        glVertex2f(s, a);
        glVertex2f(s, d);
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex2f(y + 0.1f, x + 0.1f);
        glVertex2f(y + 0.1f, x - 0.1f);
        glVertex2f(y - 0.1f, x + 0.1f);
        glVertex2f(y - 0.1f, x - 0.1f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}