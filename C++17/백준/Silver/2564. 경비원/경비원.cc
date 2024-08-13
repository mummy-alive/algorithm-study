#include<iostream>
using namespace std;
int x, y, n, nm[105], nm_c;
pair<int, int> pr[105], cr;

int f() {
	int cnt = 0;
	int dx[] = { 0, 0, x, x };
	int dy[] = { 0, y, 0, y };
	for (int i = 0; i < n; i++) {
		if (nm_c == nm[i]) {
			cnt += max(abs(pr[i].first - cr.first), abs(pr[i].second - cr.second));
			continue;
		}
		int par = 1e9;
		for (int j = 0; j < 4; j++) {
			par = min(par, abs(pr[i].first - dx[j]) + abs(pr[i].second - dy[j]) + abs(cr.first - dx[j]) + abs(cr.second - dy[j]));
		}
		cnt += par;
	}
	return cnt;
}

pair<int, int> fixer(int a, int b) {
	pair<int, int> pk;
	if (a == 1)
		return { b, 0 };
	if (a == 2) 
		return { b, y };
	if (a == 3)
		return { 0, b };
	if (a == 4)
		return { x, b };
}

int main() {
	cin >> x >> y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		nm[i] = a;
		pr[i] = fixer(a, b);
	}
	int p, q;
	cin >> p >> q;
	nm_c = p;
	cr = fixer(p, q);
	cout << f();
	return 0;
}