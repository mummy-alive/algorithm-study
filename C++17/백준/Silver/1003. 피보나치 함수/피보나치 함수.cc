#include<iostream>
using namespace std;
int t, n, k0[45] = { 1,0 }, k1[45] = { 0,1 };
int main() {
	for (int i = 2; i <= 40; i++)
	{
		k0[i] = k0[i - 1] + k0[i - 2];
		k1[i] = k1[i - 1] + k1[i - 2];
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << k0[n] << " " << k1[n] << '\n';
	}
	return 0;
}