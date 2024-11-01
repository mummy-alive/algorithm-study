#include<iostream>
#include<queue>
using namespace std;
typedef struct {
	int p, q, r, day;
} PR;
int m, n, h, arr[105][105][105];
int vst[105][105][105];
queue<PR> qu;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					qu.push({ i, j ,k, 0 });
				}
			}
		}
	}
	int dh[] = { 1, -1, 0, 0, 0, 0 }; 
	int dr[] = { 0, 0, 1, -1, 0, 0 };
	int dc[] = { 0, 0, 0, 0, 1, -1 };
	int ans = 0;
	while (!qu.empty()) {
		int p = qu.front().p;
		int q = qu.front().q;
		int r = qu.front().r;
		int day = qu.front().day;
		qu.pop();
		if (p < 0 || p >= h || q < 0 || q >=n || r < 0 || r >=m) continue;
		if (arr[p][q][r] == -1) continue;
		if (vst[p][q][r]) continue;
		vst[p][q][r] = 1;
		ans = max(ans, day);
		for (int i = 0; i < 6; i++)
			qu.push({ p + dh[i], q + dr[i], r + dc[i], day + 1 });
		
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if ((arr[i][j][k] == 0) && (!vst[i][j][k])) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}