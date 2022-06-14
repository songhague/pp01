#pragma once
class DdongF
{
public:
    float dx5, dxx5, dy5, dyy5;
    bool ddongF = false;
    DdongF()
    {
        float dx5 = 0.15f, dxx5 = 0.25f, dy5 = 0.9f, dyy5 = 1.0f;
    }
    ~DdongF()
    {

    }
    void speed()
    {
        dy5 = dy5 - 0.02f;
        dyy5 = dyy5 - 0.02f;
    }
    void draw()
    {
        if (ddongF == true) //true면 적이 아래로 나오게 false면 적이 위로 나오게
        {
            if (dy5 <= -1.0f && dyy5 <= -0.9f)
            {
                dx5 = 0.15f,
                    dxx5 = 0.25f,
                    dy5 = 0.9f,
                    dyy5 = 1.0f;
                ddongF = false;
            }
        }
        if (ddongF == false)
        {
            if (dy5 <= -1.0f && dyy5 <= -0.9f)
            {
                dx5 = 0.75f,
                    dxx5 = 0.85f,
                    dy5 = 0.9f,
                    dyy5 = 1.0f;
                ddongF = true;
            }
        }
    }
};