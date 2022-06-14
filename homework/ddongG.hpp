#pragma once
class DdongG
{
public:
    float dx6, dxx6, dy6, dyy6;
    bool ddongG = false;
    DdongG()
    {
        float dx6 = -0.25f, dxx6 = -0.15f, dy6 = 0.9f, dyy6 = 1.0f;
    }
    ~DdongG()
    {

    }
    void speed()
    {
        dy6 = dy6 - 0.03f;
        dyy6 = dyy6 - 0.03f;
    }
    void draw()
    {
        if (ddongG == true) //true면 적이 아래로 나오게 false면 적이 위로 나오게
        {
            if (dy6 <= -1.0f && dyy6 <= -0.9f)
            {
                dx6 = -0.25f,
                    dxx6 = -0.15f,
                    dy6 = 0.9f,
                    dyy6 = 1.0f;
                ddongG = false;
            }
        }
        if (ddongG == false)
        {
            if (dy6 <= -1.0f && dyy6 <= -0.9f)
            {
                dx6 = -0.85f,
                    dxx6 = -0.75f,
                    dy6 = 0.9f,
                    dyy6 = 1.0f;
                ddongG = true;
            }
        }
    }
};