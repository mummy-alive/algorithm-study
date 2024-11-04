#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int m, n, arr[15], ans[15];
void fnd(int k, int ln) {
	if (ln >= m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	int prev = 0;
	for (int i = k; i < n; i++) {
		if (arr[i] == prev) continue;
		prev = arr[i];
		ans[ln] = arr[i];
		fnd(i, ln + 1);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	fnd(0, 0);
	return 0;
}