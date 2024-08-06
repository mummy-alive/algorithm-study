#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int m, n,k, ans, area[10005];
bool vst[105][105];
void draw(int r1, int c1, int r2, int c2) {
	for (int i = min(r1, r2); i < max(r1, r2); i++) {
		for (int j = min(c1, c2); j < max(c1, c2); j++) {
			vst[i][j] = 1;
		}
	}
}
void bfs(int r, int c) {
	int acr = 0;
	queue<pair<int, int>> qu;
	qu.push({ r,c });
	while (!qu.empty()) {
		int p = qu.front().first;
		int q = qu.front().second;
		qu.pop();
		if (p < 0 || q < 0 || p >= m || q >= n)	continue;
		if (vst[p][q]) continue;
		vst[p][q] = 1;
		acr++;
		int df1[] = {0, 0, -1, 1};
		int df2[] = { -1, 1, 0, 0 };
		for (int i = 0; i < 4; i++)
			qu.push({ p + df1[i], q + df2[i] });
	}
	area[ans] = acr;
	ans++;
}
int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int r1, r2, c1, c2;
		cin >> c1 >> r1 >> c2 >> r2;
		draw(r1, c1, r2, c2);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!vst[i][j])
				bfs(i, j);
		}
	}
	cout << ans << '\n';
	sort(area, area + ans);
	for (int i = 0; i < ans; i++)
		cout << area[i]<< ' ';
	return 0;
}