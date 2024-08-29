#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[1005], sum;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n );
	for (int i = 0; i < n; i++)
	{
		sum += (n - i) * arr[i];
	}
	cout << sum;
	return 0;
}