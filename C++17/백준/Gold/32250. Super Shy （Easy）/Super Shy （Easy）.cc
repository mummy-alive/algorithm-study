#include<iostream>
using namespace std;
int n, ans, arr[3000005];
int f(int p) {
	if (p < 2) return 0;
	if (arr[p]) return arr[p];
	return arr[p] = f(p / 2) + f((p + 1) / 2);
}
int main() {
	cin >> n;
	arr[2] = 1;
	for (int i = 0; i < n; i++)
		ans = max(ans, f(i) + f(n - 1 - i) + 1);
	cout << ans;
	return 0;
}