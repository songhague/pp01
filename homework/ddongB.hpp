#pragma once
class DdongB
{
public:
    float dx1, dxx1, dy1, dyy1;
    bool ddongB = true;
    DdongB()
    {
        float dx1 = -0.3f, dxx1 = -0.2f, dy1 = 0.9f, dyy1 = 1.0f;
    }
    ~DdongB()
    {

    }
    void speed()
    {
        dy1 = dy1 - 0.009f;
        dyy1 = dyy1 - 0.009f;
    }
    void draw()
    {
        if (ddongB == true) //true면 적이 아래로 나오게 false면 적이 위로 나오게
        {
            if (dy1 <= -1.0f && dyy1 <= -0.9f)
            {
                dx1 = 0.2f,
                    dxx1 = 0.3f,
                    dy1 = 0.9f,
                    dyy1 = 1.0f;
                ddongB = false;
            }
        }
        if (ddongB == false)
        {
            if (dy1 <= -1.0f && dyy1 <= -0.9f)
            {
                dx1 = -0.3f,
                    dxx1 = -0.2f,
                    dy1 = 0.9f,
                    dyy1 = 1.0f;
                ddongB = true;
            }
        }
    }
};