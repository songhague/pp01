#pragma once
class Player
{
public:
	float x, y;
	Player()
	{
		x = 0.0f;
		y = -1.0f;
	}
	~Player()
	{

	}
	void isKeyright()
	{
		x = x + 0.01f;
	}
	void isKeyleft()
	{
		x = x - 0.01f;
	}
};