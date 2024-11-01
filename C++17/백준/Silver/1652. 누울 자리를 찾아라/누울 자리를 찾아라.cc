#include<iostream>
using namespace std;
int n, ans_a, ans_b;
string st[105];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st[i];
		st[i] = st[i] + '?';
	}
	for (int j = 0; j < n; j++)
		st[n] = st[n] + '?';

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j <= n; j++) {
			if (st[i][j] == '.') { cnt++; }
			else {
				if(cnt>=2) ans_a++;
				cnt = 0;
			}
		}
	}
	
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			if (st[i][j] == '.') { cnt++; }
			else {
				if (cnt >= 2) ans_b++;
				cnt = 0;
			}
		}
	}
	cout << ans_a << ' ' << ans_b;
	return 0;
}