#include<iostream>
using namespace std;
int arr[6000005], n, d, k, c, ans, mx;
int idx[3005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> d >> k >> c;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	idx[c] = 1;
	ans++;
	for (int i = 0; i < k; i++) {
		if (!idx[arr[i]])
			ans++;
		idx[arr[i]] += 1;
	}
	mx = ans;
	int lt = 0, rt = k - 1;
	while (rt < 2 * n - 1) {
		if (idx[arr[lt]] == 1) ans--;
		idx[arr[lt]] -= 1;
		lt++;
		rt++;
		if (idx[arr[rt]] == 0) ans++;
		idx[arr[rt]] += 1;
		mx = max(ans, mx);
	}
	cout << mx;
	return 0;
}