#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "MGameLoop.hpp"
//이벤트 헨들러 특정한 행동에 이벤트가 정의됨 이벤트가 실행했을할때 이벤트 헨들러
//콜백 내가 어떤 이벤트를 발생시켰어 그다음에 이벤트가 끝난후에 나에가 알려줘라 이게 콜백
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{//콜백함수 두개만듬
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
void play()
{
    MuSeoun_Engine::MGameLoop gLoop;
    gLoop.Run();
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
    
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        
        //glClearColor(0, 0, 1, 1);
        //glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
 
        glfwPollEvents(); 
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}