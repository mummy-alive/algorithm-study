#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, arr[105];
typedef struct PR{
	int x, y, score;
}PR;
vector<PR> vt;
bool cmp(PR a, PR b) {
	if (a.score == b.score)
		return a.x > b.x;
	return (a.score > b.score);
}
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++)
		arr[i] = 2;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vt.push_back({ a, b , c});
	}
	sort(vt.begin(), vt.end(), cmp);
	int cnt = 3;
	for (auto pr : vt) {
		if (arr[pr.x] <= 0) continue;
		if (cnt == 0) break;
		cout << pr.x << ' ' << pr.y << '\n';
		arr[pr.x]--;
		cnt--;
	}
	return 0;
}