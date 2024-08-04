#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, arr[105][105], mx;
bool check[105][105];
void bfs(int c, int r, int d) {
	queue<pair<int, int>> qu;
	qu.push({ c,r });
	while (!qu.empty()) {
		int p = qu.front().first;
		int q = qu.front().second;
		qu.pop();
		if (p < 0 || q < 0 || p >= n || q >= n)
			continue;
		if (check[p][q])
			continue;
		if (arr[p][q] <= d)
			continue;
		check[p][q] = 1;
		qu.push({ p + 1, q });
		qu.push({ p,q + 1 });
		qu.push({ p - 1, q });
		qu.push({ p, q - 1 });
	}
}
int fnd(int d) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && arr[i][j] > d) {
				bfs(i, j, d);
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i <= 100; i++) {
		memset(check, 0, sizeof(check));
		mx = max(mx, fnd(i));
	}
	cout << mx;
	return 0;
}