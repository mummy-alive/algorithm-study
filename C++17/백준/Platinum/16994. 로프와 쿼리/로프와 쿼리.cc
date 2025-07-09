#include<iostream>
#include<cstring>
#include<ext/rope>
using namespace std;
int q, n, x, y;
char st[100005];
__gnu_cxx::rope<char> rp;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> st;
	int sz = strlen(st);
	rp = st;
	cin >> q;
	while (q--) {
		cin >> n;
		if (n == 3) {
			cin >> x;
			cout << rp[x] << '\n';
		}
		else {
			cin >> x >> y;
			if (n == 1)
				rp = rp.substr(x, y - x + 1) + rp.substr(0, x) + rp.substr(y + 1, sz - y);
			else
				rp = rp.substr(0, x) + rp.substr(y + 1, sz - y) + rp.substr(x, y - x + 1);
		}
	}
	return 0;
}
