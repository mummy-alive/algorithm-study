#include<iostream>
#include<cstring>
using namespace std;
int n, m, arr[505][505], ans = 0;
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
bool idx[505][505];

void f(int r, int c, int cnt, int sum) {
	if (cnt >= 4) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int pr = r + dr[i], pc = c + dc[i];
		if (pr < 0 || pr >= n || pc < 0 || pc >= m)
			continue;
		if (!idx[pr][pc]) {
			idx[pr][pc] = 1;
			f(pr, pc, cnt + 1, sum + arr[pr][pc]);
			idx[pr][pc] = 0;
		}
	}
}

void cross(int r, int c){
	for (int i = 0; i < 4; i++) {
		bool flg = 1;
		int pp = arr[r][c];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			int pr = r + dr[j], pc = c + dc[j];
			if (pr < 0 || pr >= n || pc < 0 || pc >= m) {
				flg = 0;
				break;
			}
			pp += arr[pr][pc];
		}
		if (!flg) continue;
		ans = max(ans, pp);
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j< m; j++) {
			memset(idx, 0, sizeof(idx));
			idx[i][j] = 1;
			f(i, j, 1, arr[i][j]);
			cross(i, j);
		}
	}
	cout << ans;
	return 0;
}