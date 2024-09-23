#include<iostream>
using namespace std;
int main() {
	int n, k;
	int ans = 0;
	string st;
	bool ham[20005] = { 0 };
	cin >> n >> k;
	cin >> st;
	for (int i = 0; i < n; i++) {
		if (st[i] == 'H') continue;
		for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
			if ((st[j] == 'H') && !ham[j]) {
				ham[j] = 1;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}