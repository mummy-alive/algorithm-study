#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int ans[25], r[25];
void f(int v, int p) {
	for (int i = 0; i < n; i++) {
		if (ans[i] == v) {
			r[i] += 10000;
			return;
		}
	}
	int pt = 0;
	for (int i = 0; i < n; i++) {
		if (r[i] < r[pt])
			pt = i;
	}
	ans[pt] = v;
	r[pt] = 10000 + p;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		f(a, i);
	}
	sort(ans, ans + n);
	for (int i = 0; i < n; i++)
		if (ans[i])
			cout << ans[i] << ' ';
	return 0;
}