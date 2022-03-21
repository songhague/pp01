#include <iostream>
#include<string>

using namespace std;

class Car
{
public:
	Car()
	{
		cout << "Car�� �����մϴ�\n";
	}

	~Car()
	{
		cout << "Car�� �Ҹ��մϴ�\n";
	}

	virtual void OpenWindow()
	{
		cout << "â���� ���ϴ�\n";
	}

	virtual void ChangeGear()
	{
		cout << "�� �����դ��ϴ�\n";
	}
};

class Spark : public Car
{
public:
	Spark()
	{
		cout << "Spark�� �����մϴ�\n";
	}

	~Spark()
	{
		cout << "Spark�� �Ҹ�˴ϴ�\n";
	}

	virtual void OpenWindow()
	{
		cout << "�������� â���� ���ϴ�\n";
	}

	virtual void ChangeGear()
	{
		cout << "�������� �� �ٲߴϴ�\n";
	}
};

class Eascalade : public Car
{
public:
	Eascalade()
	{
		cout << "Eascalade�� �����մϴ�\n";
	}

	~Eascalade()
	{
		cout << "Eascalade�� �Ҹ�˴ϴ�\n";
	}

	virtual void OpenWindow()
	{
		cout << "�ڵ����� â���� ���ϴ�\n";
	}

	virtual void ChangeGear()
	{
		cout << "�ڵ����� �� �ٲߴϴ�\n";
	}
};

//������ �Լ�
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