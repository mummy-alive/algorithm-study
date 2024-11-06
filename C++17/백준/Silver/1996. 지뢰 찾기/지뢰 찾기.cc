#include<iostream>
using namespace std;
int n;
string st[1005];
int d[] = { 0, 1, -1 };
int ans[1005][1005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> st[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = 0; p < 3; p++) {
				for (int q = 0; q < 3; q++) {
					int r = i + d[p], c = j + d[q];
					if (r < 0 || r >= n || c < 0 || c >= n) continue;
					if (st[r][c] == '.') continue;
					ans[i][j] += (st[r][c] - '0');
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (st[i][j] != '.') cout << '*';
			else if (ans[i][j] > 9) cout << "M";
			else cout<< ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}