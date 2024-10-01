#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int h, w;
char st[105][105];
string ky;
bool idx[105][105];
bool key[150];
int dr[] = { 0, 0, -1, 1 }, dc[] = { 1, -1, 0, 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		memset(idx, 0, sizeof(idx)); memset(key, 0, sizeof(key));
		queue<pair<int, int>> qu, door[150];
		cin >> h >> w;
		for (int j = 0; j <= w + 1; j++)
			st[0][j] = st[h + 1][j] = '.';
		for (int i = 0; i <= h; i++)
			st[i][0] = st[i][w + 1] = '.';
		for (int i = 1; i <= h; i++) 
			for (int j = 1; j <= w; j++)
				cin >> st[i][j];
		cin >> ky;
		for (int i = 0; i < ky.size(); i++) {
			key[ky[i]] = 1;
		}
		qu.push({ 0,0 });
		while (!qu.empty()) {
			int r = qu.front().first, c = qu.front().second;
			qu.pop();
			if (r<0 || c<0 || r > h + 1 || c > w + 1) continue;
			if (st[r][c] == '*' || idx[r][c]) continue;
			if (st[r][c] >= 'A' && st[r][c] <= 'Z') {
				if (!key[st[r][c] - 'A' + 'a']) {
					door[st[r][c] - 'A' + 'a'].push({ r,c });
					continue;
				}
			}
			idx[r][c] = 1;
			if (st[r][c] == '$') ans++;
			else if (st[r][c] >= 'a' && st[r][c] <= 'z') {
				if (!key[st[r][c]]) {
					key[st[r][c]] = 1;
					while (!door[st[r][c]].empty()) {
						qu.push(door[st[r][c]].front());
						door[st[r][c]].pop();
					}
				}
			}
			for (int i = 0; i < 4; i++)
				qu.push({ r + dr[i], c + dc[i] });
		}
		cout << ans << '\n';
	}
	return 0;
}