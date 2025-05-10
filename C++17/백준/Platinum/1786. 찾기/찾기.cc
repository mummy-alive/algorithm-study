#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
string t, p;
int pi[1000005];

void makePi() {
	int pt = 0, m = int(p.size());

	for (int i = 1; i < m; i++) {
		while ((pt > 0) && (p[i] != p[pt])) {
			pt = pi[pt - 1];
		}
		if (p[i] == p[pt])
			pi[i] = ++pt;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, t);
	getline(cin, p);
	makePi();

	int pt = 0;
	vector<int> ans;
	int n = t.size(), m = p.size();
	for (int i = 0; i < n; i++) {
		while (pt > 0 && t[i] != p[pt]) {
			pt = pi[pt - 1];
		}
		if (t[i] == p[pt]) {
			if (pt == m - 1) {
				ans.push_back(i - m + 2);
				pt = pi[pt];
			}
			else pt++;
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << ' ';
	return 0;
}