#include<iostream>
#define SZ 1000005
using namespace std;
int n, arr[SZ], ln, par[SZ];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		
		int pos = lower_bound(par, par + ln, arr[i]) - par;
		if (pos == ln) {
			par[ln] = arr[i];
			ln++;
		}
		else {
			par[pos] = arr[i];
		}
	}
	cout << ln;
	return 0;
}