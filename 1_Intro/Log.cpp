#include <iostream>

using namespace std;

int log(int number)
{
	int counter = 0;
	while (true)
	{
		if (number / 2 >= 1)
		{
			number /= 2;
			counter++;
		}
		else
		{
			break;
		}
	}
	return counter;
}

int main()
{
	int t;
	cin >> t;
	int number;
	for (int i = 0; i < t; i++)
	{
		cin >> number;
		cout << log(number) << endl;
	}
	return 0;
}