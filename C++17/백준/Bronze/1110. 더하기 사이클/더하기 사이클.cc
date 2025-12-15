#include<iostream>
using namespace std;
int n, sum, par;

int func(int num) {
	int ac = 0;
	while (num)
	{
		ac += num % 10;
		num /= 10;
	}
	return ac;
}

int main() {
	cin >> n;
	par = n;
	while (true)
	{
		sum++;
		par = (par % 10) * 10 + (func(par) % 10);
		if (n == par)
		{
			cout << sum;
			return 0;
		}
	}
	return 0;
}