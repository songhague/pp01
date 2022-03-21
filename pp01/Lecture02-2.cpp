#include <iostream>
#include<string>

using namespace std;

class Car
{
public:
	Car()
	{
		cout << "Car를 생성합니다\n";
	}

	~Car()
	{
		cout << "Car를 소멸합니다\n";
	}

	virtual void OpenWindow()
	{
		cout << "창문을 엽니다\n";
	}

	virtual void ChangeGear()
	{
		cout << "기어를 변경합ㄴ니다\n";
	}
};

class Spark : public Car
{
public:
	Spark()
	{
		cout << "Spark를 생성합니다\n";
	}

	~Spark()
	{
		cout << "Spark를 소멸됩니다\n";
	}

	virtual void OpenWindow()
	{
		cout << "수동으로 창문을 엽니다\n";
	}

	virtual void ChangeGear()
	{
		cout << "수동으로 기어를 바꿉니다\n";
	}
};

class Eascalade : public Car
{
public:
	Eascalade()
	{
		cout << "Eascalade를 생성합니다\n";
	}

	~Eascalade()
	{
		cout << "Eascalade를 소멸됩니다\n";
	}

	virtual void OpenWindow()
	{
		cout << "자동으로 창문를 엽니다\n";
	}

	virtual void ChangeGear()
	{
		cout << "자동으로 기어를 바꿉니다\n";
	}
};

//운전자 함수
void main() 
{
	int carNum = 2;
	//Car* c[2];
	Car** c;
	c = new Car * [carNum];
	c[0] = new Spark();
	c[1] = new Eascalade();

	for (size_t i = 0; i < 2; i++)
	{
		c[i]->OpenWindow();
		c[i]->ChangeGear();
		delete(c[i]);
	}

}