#include <vector>
#include <iostream>

using namespace std;

template<typename T>

T sum(T a, T b)
{
	return a + b;
}

int main()
{
	vector<int>a;//<> 탬플릿

	cout << sum<double>(5.0, 3.434) << endl;//쓰면 좋지만 많이 느려진다

	a.push_back(1);
	a.push_back(2);

	cout << a.size() << endl;

	a.push_back(4);
	a.push_back(8);
	a.push_back(16);

	cout << a.size() << endl;

	return 0;
}