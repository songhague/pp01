#pragma once
class DdongD
{
public:
    float dx3, dxx3, dy3, dyy3;
    bool ddongD = false;
    DdongD()
    {
        float dx3 = -0.7f, dxx3 = -0.6f, dy3 = 0.9f, dyy3 = 1.0f;
    }
    ~DdongD()
    {

    }
    void speed()
    {
        dy3 = dy3 - 0.009f;
        dyy3 = dyy3 - 0.009f;
    }
    void draw()
    {
        if (ddongD == true) //true면 적이 아래로 나오게 false면 적이 위로 나오게
        {
            if (dy3 <= -1.0f && dyy3 <= -0.9f)
            {
                dx3 = 0.6f,
                    dxx3 = 0.7f,
                    dy3 = 0.9f,
                    dyy3 = 1.0f;
                ddongD = false;
            }
        }
        if (ddongD == false)
        {
            if (dy3 <= -1.0f && dyy3 <= -0.9f)
            {
                dx3 = -0.7f,
                    dxx3 = -0.6f,
                    dy3 = 0.9f,
                    dyy3 = 1.0f;
                ddongD = true;
            }
        }
    }
};