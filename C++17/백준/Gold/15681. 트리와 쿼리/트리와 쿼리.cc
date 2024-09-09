#include<iostream>
#include<vector>
using namespace std;
int n, r, q, cnt[100005];
vector<int> vt[100005];
bool idx[100005];
int f(int v) {
	idx[v] = 1;
	cnt[v]++;
	for (auto x : vt[v]) {
		if (!idx[x])
			cnt[v] += f(x);
	}
	return cnt[v];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> r >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	f(r);
	while (q--) {
		int query;
		cin >> query;
		cout << cnt[query] << '\n';
	}
	return 0;
}