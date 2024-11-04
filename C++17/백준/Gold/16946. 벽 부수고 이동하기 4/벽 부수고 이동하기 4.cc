#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int n, m, gr=0, idx[1005][1005], cnt[1000005];
string st[1005];
int dr[] = { 0, 0, 1, -1 }, dc[] = { 1, -1, 0, 0 };
void bfs(int r, int c) {
	gr++;
	int sum = 0;
	queue<pair<int, int>> qu;
	qu.push({ r, c });
	while (!qu.empty()) {
		int p = qu.front().first;
		int q = qu.front().second;
		qu.pop();
		if (p < 0 || p >= m || q < 0 || q >= n) continue;
		if (st[p][q] == '1' || idx[p][q]) continue;
		idx[p][q] = gr;
		sum++;
		for (int i = 0; i < 4; i++)
			qu.push({ p + dr[i], q + dc[i] });
	}
	cnt[gr] = sum;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> st[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (st[i][j] == '1' || idx[i][j]) continue;
			bfs(i, j);
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (st[i][j] == '0') {
				cout << 0;
				continue;
			}
			set<int> par;
			for (int k = 0; k < 4; k++) {
				if (i + dr[k] < 0 || i + dr[k] >= m || j + dc[k] < 0 || j + dc[k] >= n)
					continue;
				else par.insert(idx[i + dr[k]][j + dc[k]]);
			}
			int ans = 1;
			for (auto it = par.begin(); it != par.end(); ++it)
				ans += cnt[*it];
			cout << ans%10;
		}
		cout << '\n';
	}
	return 0;
}