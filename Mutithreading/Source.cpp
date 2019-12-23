#include<thread>
#include<iostream>
using namespace std;

void funPtr(int x)
{
	for (int i = 0; i < x; i++)
		cout << "Inside funPtr i = " << i << endl;
}

class FunObj
{
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
			cout << "Inside FunObj i = " << i << endl;
	}
};

int main()
{
	cout << "Creating threads:" << endl;

	//Create a thread using function pointer
	thread t1 (funPtr, 20);

	//create a thread using function object
	thread t2(FunObj(), 20);

	//create a thread object using lambda expression
	auto fun = 	[](int x)
	{
					for (int i = 0; i < x; i++)
						cout << "Inside lambda i = " << i << endl;
	};

	thread t3(fun, 20);

	t1.join();
	t2.join();
	t3.join();

	getchar();
	return 0;
}
