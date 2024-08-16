#include<iostream>
using namespace std;
int x, y, k, a[105], b[105], arr[105], ans;
int main() {
	cin >> x >> y >> k;
	for (int i = 0; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) arr[i] = b;
		else if (a == 4)
			arr[i] = b + x;
		else if (a == 2)
			arr[i] = (x - b) + x + y;
		else if (a == 3)
			arr[i] = (y - b) + x + x + y;
	}
	for (int i = 0; i < k; i++) {
		int par = abs(arr[k] - arr[i]);
		ans += min(par, 2 * (x + y) - par);
	}
	cout << ans;
	return 0;
}