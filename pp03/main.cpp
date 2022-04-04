#include <iostream>
using namespace std;

class A 
{
public :
	virtual void dynamic_print()
	{
		cout << "´ÙÀÌ³ª¹ÌÅ© µ¥Çò\n";
	}

	 void static_print() 
	{
		cout << "µ¥Çì\n";
	}
};

class B : public A
{
	public :
		void dynamic_print()
		{
			cout << "´ÙÀÌ³ª¸¶Å© ÇìÇò\n";
		}

		void static_print()
		{
			cout << "ÇìÂm\n";
		}

		void static_print(int a)
		{
			cout << a << "ÇìÂm\n";
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