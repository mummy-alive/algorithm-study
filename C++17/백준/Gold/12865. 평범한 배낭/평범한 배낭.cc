#include<iostream>
using namespace std;
int n, k, ans;
int dp[100005];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	for (int i = 0; i <= k; i++)
		ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}