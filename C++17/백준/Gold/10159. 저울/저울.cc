#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n, m;
bool c1[105], c2[105];
vector<int> vt1[105], vt2[105];
void fnd1(int n) {
	if (c1[n]) return;
	c1[n] = 1;
	for (auto x : vt1[n]) {
		fnd1(x);
	}
}

void fnd2(int n) {
	if (c2[n]) return;
	c2[n] = 1;
	for (auto x : vt2[n]) {
		fnd2(x);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vt1[u].push_back(v);
		vt2[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		fnd1(i);
		fnd2(i);
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (c1[j] || c2[j])
				cnt++;
		cout << n - cnt << '\n';
	}
	return 0;
}