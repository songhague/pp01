#include <GLFW/glfw3.h>//전처리부터 읽어짐 그리고 메인 부터 봄
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "opengl32")//lib이 안에 오픈지엘을 가져온다ㄴㄴㄴㄴㄴㄴㄴㄴㄴㄴ
//컴파일러에게 명령어 전달 전처리기에 키워드를 내려줌 comment 외부에있는 파일을 알려주

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
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//원도우를 만들갰다 윈도우를 내놔라ㄴㄴ
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);//glcontext잡어서 windowd에 넣음
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//glfw앞에 붙은게 윈도우 창 상태를 바꿔주는거
        ratio = width / (float)height;

        glClearColor(0.7f, 0.7f, 0.7f, 1);//rgb임 
        //double말고 float쓰는 이유 더블보다 빠르게 사용이 가능해서
        glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_POINT);//점을 그리겠다. 앞으로 그리느건 점이다
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

        //프리미티브 원시적인
        //glLineWidth(10.0);
        //glBegin(GL_LINES);//꼭지점 은 짝수개 있어야 함. 연결되지 않은 점은 그리지 않음
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(0.0f, 0.0f);
        //glVertex2f(1.0f, 1.0f);
        //glColor3f(0.0f, 0.0f, 1.0f);
        //glVertex2f(0.0f, 0.0f);
        //glVertex2f(1.0f, -1.0f);
        //glEnd();


        glfwSwapBuffers(window);//버퍼 스압

        glfwPollEvents();//이벤트 q 메세지가 들어가있느 없는지 확인 메세지가 있으면 키콜백 아니면 에러콜백이 실행됨
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}