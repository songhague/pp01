#pragma once
class DdongE
{
public:
    float dx4, dxx4, dy4, dyy4;
    bool ddongE = false;
    DdongE()
    {
        float dx4 = -0.9f, dxx4 = -0.8f, dy4 = 0.9f, dyy4 = 1.0f;
    }
    ~DdongE()
    {

    }
    void speed()
    {
        dy4 = dy4 - 0.02f;
        dyy4 = dyy4 - 0.02f;
    }
    void draw()
    {
        if (ddongE == true) //true�� ���� �Ʒ��� ������ false�� ���� ���� ������
        {
            if (dy4 <= -1.0f && dyy4 <= -0.9f)
            {
                dx4 = 0.8f,
                    dxx4 = 0.9f,
                    dy4 = 0.9f,
                    dyy4 = 1.0f;
                ddongE = false;
            }
        }
        if (ddongE == false)
        {
            if (dy4 <= -1.0f && dyy4 <= -0.9f)
            {
                dx4 = -0.9f,
                    dxx4 = -0.8f,
                    dy4 = 0.9f,
                    dyy4 = 1.0f;
                ddongE = true;
            }
        }
    }
};