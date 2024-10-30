#include<iostream>
using namespace std;
int n, m, k;
int par[30005], arr[30005], cost[30005], sum[30005]; // cost, sum
int dp[30005][3005];
void uni(int u, int v) {
	while (u != par[u])
		u = par[u];
	while (v != par[v])
		v = par[v];
	if (u < v) par[v] = u;
	else par[u] = v;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		uni(u, v);
	}
	for (int i = 1; i <= n; i++) {
		int p = i;
		while (p != par[p]) p = par[p];
		cost[p] += arr[i];
		sum[p]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!sum[i]) {
			for (int j = 0; j < k; j++)
				dp[i][j] = dp[i - 1][j];
		}
		else {
			for (int j = 0; j < sum[i]; j++)
				dp[i][j] = dp[i - 1][j];
			for (int j = sum[i]; j < k; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - sum[i]] + cost[i]);
		}
	}
	int mx = 0;
	for (int j = 0; j < k; j++)
		mx = max(mx, dp[n][j]);
	cout << mx;
	return 0;
}