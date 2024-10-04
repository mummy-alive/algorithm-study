#include<iostream>
#include<vector>
#define SZ 1000005
using namespace std;
int n;
bool idx[SZ] = { 0 };
int dp[SZ][5] = { 0 };
vector<int> vt[SZ];
void dfs(int v) {
	if (idx[v]) return;
	idx[v] = 1;
	dp[v][1] = 1;
	for (auto x : vt[v]) {
		if (idx[x]) continue;
		dfs(x);
		dp[v][0] += dp[x][1];
		dp[v][1] += min(dp[x][0], dp[x][1]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}