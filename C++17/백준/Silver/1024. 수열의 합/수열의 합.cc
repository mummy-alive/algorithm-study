#include<iostream>
using namespace std;
typedef long long LL;
LL n, l;
int rs(int st, int ed) {
	return (ed * (ed + 1) - st * (st - 1)) / 2;
}
int main() {
	cin >> n >> l;
	int st = -1, cnt = 0;
	for (int i = l; i <= 100; i++) {
		int t = i * (i - 1) / 2;
		if ((n - t) >= 0 && (n - t) % i == 0 ) {
			st = (n - t) / i;
			cnt = i;
			break;
		}
	}
	if (st < 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < cnt; i++)
		cout << st + i << ' ';
	return 0;
}