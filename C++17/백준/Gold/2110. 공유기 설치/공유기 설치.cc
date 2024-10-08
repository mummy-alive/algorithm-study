#include<iostream>
#include<algorithm>
using namespace std;
int n, c, arr[200005], mx;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int lt = 1, rt = arr[n - 1] - arr[0];
	while (lt <= rt) {
		int md = (lt + rt) / 2;
		int cnt = 1;
		int st = arr[0];
		for (int i = 1; i < n; i++) {
			if ((arr[i] - st) >= md) {
				cnt++;
				st = arr[i];
			}
		}
		if (cnt >= c) {
			mx = max(mx, md);
			lt = md + 1;
		}
		else rt = md - 1;
	}
	cout << mx;
	return 0;
}