#include <GLFW/glfw3.h>//穿坦軒採斗 石嬢像 益軒壱 五昔 採斗 砂
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>

#pragma comment(lib, "opengl32")//lib戚 照拭 神蚤走燭聖 亜閃紳陥いいいいいいいいいい
//陳督析君拭惟 誤敬嬢 穿含 穿坦軒奄拭 徹趨球研 鎧形捜 comment 須採拭赤澗 督析聖 硝形爽

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
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//据亀酔研 幻級虻陥 制亀酔研 鎧竃虞いい
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);//glcontext説嬢辞 windowd拭 隔製
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//glfw蒋拭 細精惟 制亀酔 但 雌殿研 郊蚊爽澗暗
        ratio = width / (float)height;

        glClearColor(0.7f, 0.7f, 0.7f, 1);//rgb績 
        //double源壱 float床澗 戚政 希鷺左陥 匙牽惟 紫遂戚 亜管背辞
        glClear(GL_COLOR_BUFFER_BIT);



        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, 0.3f);
            glVertex2f(-0.5f, 0.1f);
            glVertex2f(-0.7f, 0.1f);
            glVertex2f(-0.5f, 0.3f);
            glVertex2f(-0.7f, 0.3f);
            glVertex2f(-0.7f, 0.1f);
            glEnd();
        }
        else {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(-0.5f, -0.2f);
            glVertex2f(-0.7f, -0.2f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(-0.7f, 0.0f);
            glVertex2f(-0.7f, -0.2f);
            glEnd();
        }
        glfwSwapBuffers(window);//獄遁 什笑

        glfwPollEvents();//戚坤闘 q 五室走亜 級嬢亜赤汗 蒸澗走 溌昔 五室走亜 赤生檎 徹紬拷 焼艦檎 拭君紬拷戚 叔楳喫
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}