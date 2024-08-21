#include<iostream>
#define MD 10007
using namespace std;
int n, ans;
int dp[15][1005];
int main() {
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;
	for (int j = 2; j <= n; j++)
		for (int i = 0; i < 10; i++)
			dp[i][j] = (dp[max(0, i - 1)][j] + dp[i][j - 1]) % MD;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[i][n]) % MD;
	cout << ans;
	return 0;
}