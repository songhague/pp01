#include <GLFW/glfw3.h>//��ó������ �о��� �׸��� ���� ���� ��
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "opengl32")//lib�� �ȿ� ���������� �����´٤�������������������
//�����Ϸ����� ��ɾ� ���� ��ó���⿡ Ű���带 ������ comment �ܺο��ִ� ������ �˷���

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
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//�����츦 ���鰺�� �����츦 �����󤤤�
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);//glcontext�� windowd�� ����
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//glfw�տ� ������ ������ â ���¸� �ٲ��ִ°�
        ratio = width / (float)height;

        glClearColor(0.7f, 0.7f, 0.7f, 1);//rgb�� 
        //double���� float���� ���� ������ ������ ����� �����ؼ�
        glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_POINT);//���� �׸��ڴ�. ������ �׸����� ���̴�
        //glColor3f(1.0f, 0.0f, 0.0f);  
        //glVertex2f(0.0f,0.0f);
        //glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);

        glVertex2f(1.0f, -1.0f);
        glEnd();

        //������Ƽ�� ��������
        //glLineWidth(10.0);
        //glBegin(GL_LINES);//������ �� ¦���� �־�� ��. ������� ���� ���� �׸��� ����
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(0.0f, 0.0f);
        //glVertex2f(1.0f, 1.0f);
        //glColor3f(0.0f, 0.0f, 1.0f);
        //glVertex2f(0.0f, 0.0f);
        //glVertex2f(1.0f, -1.0f);
        //glEnd();


        glfwSwapBuffers(window);//���� ����

        glfwPollEvents();//�̺�Ʈ q �޼����� ���ִ� ������ Ȯ�� �޼����� ������ Ű�ݹ� �ƴϸ� �����ݹ��� �����
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}