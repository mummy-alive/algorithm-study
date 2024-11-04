#include<iostream>
using namespace std;
int n, ans[3];
bool arr[15][15], rr[20], cc[20];
void fnd(int r, int c, int cnt, bool mode) {
	if (c >= n) {
		r++;
		c = (c % 2 == 0 ? 1 : 0);
	}
	if (r >= n) {
		ans[mode] = max(ans[mode], cnt);
		return;
	}
	if (arr[r][c] && !cc[r - c + n - 1] && !rr[r + c]) {
		cc[r - c + n - 1] = rr[r + c] = 1;
		fnd(r, c + 2, cnt + 1, mode);
		cc[r - c + n - 1] = rr[r + c] = 0;
	}
	fnd(r, c + 2, cnt, mode);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	fnd(0, 0, 0, 0);
	fnd(0, 1, 0, 1);
	cout << ans[0] + ans[1];
	return 0;
}