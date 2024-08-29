#include<iostream>
using namespace std;
int n, k, ans;
bool idx[20005];
string st;
int main() {
	cin >> n >> k;
	cin >> st;
	for (int i = 0; i < n; i++) {
		if (st[i] == 'P') {
			for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
				if ((st[j] == 'H') && !idx[j]) {
					ans++;
					idx[j] = 1;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}