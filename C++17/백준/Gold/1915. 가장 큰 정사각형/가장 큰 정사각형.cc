#include<iostream>
using namespace std;
int dp[1005][1005] = { 0 };
bool arr[1005][1005] = { 0 };
int n, m;
int main() {
	cin >> n >> m;
	string st[1005];
	for (int i = 0; i < n; i++)
		cin >> st[i];
;	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = (st[i - 1][j - 1] == '1' ? 1 : 0);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	for (int k = 1; k <= min(n, m); k++) {
		bool flg = 0;
		for (int i = k; i <= n; i++) {
			for (int j = k; j <= m; j++) {
				int par = dp[i][j] - (dp[i - k][j] + dp[i][j - k]) + dp[i - k][j - k];
				if (par == k * k) {
					flg = 1;
					break;
				}
			}
			if (flg) break;
		}
		if (!flg) {
			cout << (k - 1) * (k - 1);
			return 0;
		}
	}
	cout << min(n, m) * min(n, m);
	return 0;
}