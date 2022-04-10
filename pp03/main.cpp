#include <iostream>
using namespace std;
//4주차
class A 
{
public :
	virtual void dynamic_print()
	{
		cout << "다이나미크 데헷\n";
	}

	 void static_print() 
	{
		cout << "데헤\n";
	}
};

class B : public A
{
	public :
		void dynamic_print()
		{
			cout << "다이나마크 헤헷\n";
		}

		void static_print()
		{
			cout << "헤헿\n";
		}

		void static_print(int a)
		{
			cout << a << "헤헿\n";
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