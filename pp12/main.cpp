#define _CRT_SECURE_NO_WARNINGS

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "MMath.hpp"
#include "Player.hpp"

#pragma comment(lib, "OpenGL32")

//glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 512, 512, 0, GL_RED,
//    GL_LUMINANCE, GL_BYTE, image);
/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;


void makeCheckImage(void)
{
    int i, j, c;

    for (i = 0; i < checkImageHeight; i++) { //����ư ������ �ø� ������ �����ش� üũ���� �׸��°�
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;//0x8 = 8 16������ ���߾� (^ �ΰ��� ������ 0 �Ѱ��� �ٸ��� 0)
            checkImage[i][j][0] = (GLubyte)c;//RGB
            checkImage[i][j][1] = (GLubyte)c;
            checkImage[i][j][2] = (GLubyte)c;
            checkImage[i][j][3] = (GLubyte)255;//GLubyte ������������ �������� ����� ����
        }
    }
}
//�̺��� ��ũ �ٷΰ���
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//��ŷ�� ���Ѵ�.

    glGenTextures(1, &texName);//�ؽ��� �����Ѵ�. ���ε� ���ش�. ���ε� ���°� �Ʒ� ���� ������ 1���� �׸��� ������ְ� �̸��� textname�̴� 2d�̹�����.
    glBindTexture(GL_TEXTURE_2D, texName);//�տ��� �ּҰ� �� �ּҰ��� �ִ� ���� 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,//RGB�� ����.
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage);
}

//��Ʈ�� ����� �� �������� �ٽ� ����ü�� �������. �Լ�ó���� ���ϰ� �Ϸ�����.
typedef struct tagBITMAPHEADER {
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    RGBQUAD hRGB[256];
}BITMAPHEADER;

BYTE* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* imgSize, const char* filename)
{
    FILE* fp = fopen(filename, "rb");	//������ �����б���� ����
    if (fp == NULL)
    {
        printf("���Ϸε��� �����߽��ϴ�.\n");	//fopen�� �����ϸ� NULL���� ����
        return NULL;
    }
    else
    {
        fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//��Ʈ��������� �б�
        fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//��Ʈ��������� �б�
        fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//�����ȷ�Ʈ �б�

        int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//�̹��� ������ ���
        *imgSize = imgSizeTemp;	// �̹��� ����� ���� ������ �Ҵ�

        BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp);	//�̹���ũ�⸸ŭ �޸��Ҵ�
        fread(image, sizeof(BYTE), imgSizeTemp, fp);//�̹��� ũ�⸸ŭ ���Ͽ��� �о����
        fclose(fp);
        return image;
    }
}

void ChangeRGB(RGBQUAD* originalhRGB, RGBQUAD* outputhRGB, int maniplRed, int maniplBlue, int maniplGreen)
{
    //Ŭ���� ó���� outputhRGB�� �� ���� �Ҵ�
    for (int i = 0; i < 256; i++)
    {
        if (originalhRGB[i].rgbRed + maniplRed > 255)
            outputhRGB[i].rgbRed = 255;
        else if (originalhRGB[i].rgbRed + maniplRed < 0)
            outputhRGB[i].rgbRed = 0;
        else
            outputhRGB[i].rgbRed = originalhRGB[i].rgbRed + maniplRed;

        if (originalhRGB[i].rgbBlue + maniplBlue > 255)
            outputhRGB[i].rgbBlue = 255;
        else if (originalhRGB[i].rgbBlue + maniplBlue < 0)
            outputhRGB[i].rgbBlue = 0;
        else
            outputhRGB[i].rgbBlue = originalhRGB[i].rgbBlue + maniplBlue;

        if (originalhRGB[i].rgbGreen + maniplGreen > 255)
            outputhRGB[i].rgbGreen = 255;
        else if (originalhRGB[i].rgbGreen + maniplGreen < 0)
            outputhRGB[i].rgbGreen = 0;
        else
            outputhRGB[i].rgbGreen = originalhRGB[i].rgbGreen + maniplGreen;
    }

}


void WriteBitmapFile(BITMAPHEADER outputHeader, BYTE* output, int imgSize, const char* filename)
{
    FILE* fp = fopen(filename, "wb");//������ ����������� ����

    fwrite(&outputHeader.bf, sizeof(BITMAPFILEHEADER), 1, fp);//��Ʈ�������������
    fwrite(&outputHeader.bi, sizeof(BITMAPINFOHEADER), 1, fp);//��Ʈ�������������
    fwrite(&outputHeader.hRGB, sizeof(RGBQUAD), 256, fp);//�����ȷ�Ʈ ����
    fwrite(output, sizeof(BYTE), imgSize, fp);//�̹����ε������� ����
    fclose(fp);
}



int LoadBitmap()
{
    BITMAPHEADER originalHeader;	//��Ʈ���� ����κ��� ���Ͽ��� �о� ������ ����ü
    BITMAPHEADER outputHeader;	//������ ���� ����κ��� ������ ����ü
    int imgSize;//�̹����� ũ�⸦ ������ ����
    BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, "lena_gray.bmp"); //��Ʈ�������� �о� ȭ�������� ����
    if (image == NULL) return 0;        //���� �б⿡ �����ϸ� ���α׷� ����
    BYTE* output = (BYTE*)malloc(sizeof(BYTE) * imgSize);	//������� ������ ������ ���� �� �޸� �Ҵ�
    outputHeader = originalHeader;				//��������� ������������ �Ҵ�

    /*��⿡�ٰ� ������ ó���� �ڵ尡 ���� �˴ϴ�.*/
       //������� ��⸦ 50��ŭ ������Ų ���� ����
    ChangeRGB(originalHeader.hRGB, outputHeader.hRGB, 50, 50, 50);
    WriteBitmapFile(outputHeader, output, imgSize, "output1.bmp");

    //ȭ������ ����
    for (int i = 0; i < imgSize; i++)
    {
        output[i] = image[i];
    }

    free(image);
    free(output);

    return 0;
}


Player* p = new Player(0.1f, 0.9f, 0.9f, MuSeoun::vec3(1.0f, 0.0f, 0.0f));
Player* e = new Player(0.1f, 0.0f, 0.0f, MuSeoun::vec3(0.0f, 0.0f, 1.0f));

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        p->MoveUp(0.01f);
    if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
        p->MoveUp(0.0f);
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        p->MoveUp(-0.01f);
    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
        p->MoveUp(0.0f);
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        p->MoveRight(0.01f);
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        p->MoveRight(-0.01f);
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);

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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    init();

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (int i = 0; i < 4; i++)
        {
            if (p->quad[2].x < e->quad[i].x && e->quad[i].x < p->quad[1].x)
            {
                if (p->quad[2].y < e->quad[i].y && e->quad[i].y < p->quad[1].y)
                {
                    printf("�浹!!\n");
                }
            }

        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);//GL_DECAL �ؽ�Ʈ�� �԰ڴ�.
        glBindTexture(GL_TEXTURE_2D, texName);
        glBegin(GL_QUADS);//��4�� ������ �׸� �ܵ����
        glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);

        glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
        glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    delete(p);
    delete(e);
    exit(EXIT_SUCCESS);
}