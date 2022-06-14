#pragma once
class DdongC
{
public:
    float dx2, dxx2, dy2, dyy2;
    bool ddongC = false;
    DdongC()
    {
        float dx2 = -0.5f, dxx2 = -0.4f, dy2 = 0.9f, dyy2 = 1.0f;
    }
    ~DdongC()
    {

    }
    void speed()
    {
        dy2 = dy2 - 0.01f;
        dyy2 = dyy2 - 0.01f;
    }
    void draw()
    {
        if (ddongC == true)
        {
            if (dy2 <= -1.0f && dyy2 <= -0.9f)
            {
                dx2 = 0.4f,
                    dxx2 = 0.5f,
                    dy2 = 0.9f,
                    dyy2 = 1.0f;
                ddongC = false;
            }
        }
        if (ddongC == false)
        {
            if (dy2 <= -1.0f && dyy2 <= -0.9f)
            {
                dx2 = -0.5f,
                    dxx2 = -0.4f,
                    dy2 = 0.9f,
                    dyy2 = 1.0f;
                ddongC = true;
            }
        }
    }
};