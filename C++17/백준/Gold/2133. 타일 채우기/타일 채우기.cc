#include<iostream>
#define MD 1000000007
using namespace std;
typedef long long LL;
LL n, dp[5005], plur = 1;
int main() {
	cin >> n;
	dp[0] = 1;
	dp[2] = 3;
	for (LL i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2] * 3 + plur * 2;
		plur += dp[i - 2];
	}
	cout << dp[n];
	return 0;
}