#include<iostream>
using namespace std;
int n, arr[10005][5];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		arr[i][0] = max(arr[i-1][0], max(arr[i - 1][1], arr[i - 1][2]));
		arr[i][1] = arr[i - 1][0] + k;
		arr[i][2] = arr[i - 1][1] + k;
	}
	cout << max(arr[n][0], max(arr[n][1], arr[n][2]));
	return 0;
}