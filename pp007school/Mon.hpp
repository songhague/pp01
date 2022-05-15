#pragma once

class Mon
{
public:
	int x;
	int y;
	Mon()
	{
		x = 60;
		y = 7;

	}
	~Mon() {}

	void Monmove()
	{
		if (x >= 10)
		{
			x = x - 1;
		}
		else
		{
			x = 60;

		}
	}
};