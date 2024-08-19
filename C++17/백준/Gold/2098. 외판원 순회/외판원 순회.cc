#include<iostream>
#include<cstring>
using namespace std;
int n, dp[20][1 << 16], arr[20][20], ans = 1e9;

int f(int v, int bt, int ed) {
	int mn = 1e9;
	if (dp[v][bt])
		return dp[v][bt];
	if (bt == ((1 << n) - 1))
		return arr[v][ed] ? arr[v][ed] : 1e9;
	for (int i = 0; i < n; i++) {
		if (!(bt & (1 << i)) && arr[v][i] != 0)
			mn = min(mn, arr[v][i] + f(i, bt + (1 << i), ed));
	}
	return dp[v][bt] = mn;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << f(0, 1 << 0, 0);
	return 0;
}