#pragma once
class DdongA
{
public:
    float dx, dxx, dy, dyy;
    bool ddongA = true;
    DdongA()
    {
        float dx = -0.1f, dxx = 0.0f, dy = 0.9f, dyy = 1.0f;
    }
    ~DdongA()
    {

    }
    void speed()
    {
        dy = dy - 0.005f;
        dyy = dyy - 0.005f;
    }
    void draw()
    {
        if (ddongA == true) //true면 적이 아래로 나오게 false면 적이 위로 나오게
        {
            if (dy <= -1.0f && dyy <= -0.9f)
            {
                dx = 0.0f,
                    dxx = 0.1f,
                    dy = 0.9f,
                    dyy = 1.0f;
                ddongA = false;
            }
        }
        if (ddongA == false)
        {
            if (dy <= -1.0f && dyy <= -0.9f)
            {
                dx = -0.1f,
                    dxx = 0.0f,
                    dy = 0.9f,
                    dyy = 1.0f;
                ddongA = true;
            }
        }
    }
};