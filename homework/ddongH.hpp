#pragma once
class DdongH
{
public:
    float dx7, dxx7, dy7, dyy7;
    bool ddongH = false;
    DdongH()
    {
        float dx7 = 0.4f, dxx7 = 0.6f, dy7 = 0.9f, dyy7 = 1.0f;
    }
    ~DdongH()
    {

    }
    void speed()
    {
        dy7 = dy7 - 0.003f;
        dyy7 = dyy7 - 0.003f;
    }
    void draw()
    {
        if (ddongH == true) //true면 적이 아래로 나오게 false면 적이 위로 나오게
        {
            if (dy7 <= -1.0f && dyy7 <= -0.9f)
            {
                dx7 = -0.6f,
                    dxx7 = -0.4f,
                    dy7 = 0.9f,
                    dyy7 = 1.0f;
                ddongH = false;
            }
        }
        if (ddongH == false)
        {
            if (dy7 <= -1.0f && dyy7 <= -0.9f)
            {
                dx7 = 0.4f,
                    dxx7 = 0.6f,
                    dy7 = 0.9f,
                    dyy7 = 1.0f;
                ddongH = true;
            }
        }
    }
};