#include<iostream>
#define MD 10007
using namespace std;
int n, ans;
int dp[15] = { 1 };
int main() {
	cin >> n;
	for (int j = 1; j <= n+1; j++)
		for (int i = 1; i < 10; i++)
			dp[i] = (dp[i] + dp[i - 1]) % MD;
	cout << dp[9];
	return 0;
}