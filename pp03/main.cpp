#include <iostream>
using namespace std;
//4����
class A 
{
public :
	virtual void dynamic_print()
	{
		cout << "���̳���ũ ����\n";
	}

	 void static_print() 
	{
		cout << "����\n";
	}
};

class B : public A
{
	public :
		void dynamic_print()
		{
			cout << "���̳���ũ ����\n";
		}

		void static_print()
		{
			cout << "���m\n";
		}

		void static_print(int a)
		{
			cout << a << "���m\n";
		}
};

void main() 
{
	A* temp;
	B* tempB = new B();
	temp = tempB;
	temp->static_print();
	tempB->static_print();

	temp->dynamic_print();
	tempB->dynamic_print();
}