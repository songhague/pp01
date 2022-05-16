#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "MGameLoop.hpp"
//�̺�Ʈ ��鷯 Ư���� �ൿ�� �̺�Ʈ�� ���ǵ� �̺�Ʈ�� ���������Ҷ� �̺�Ʈ ��鷯
//�ݹ� ���� � �̺�Ʈ�� �߻����׾� �״����� �̺�Ʈ�� �����Ŀ� ������ �˷���� �̰� �ݹ�
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{//�ݹ��Լ� �ΰ�����
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