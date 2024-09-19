#include<iostream>
#include<set>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		int k;
		multiset<int> ms;
		cin >> k;
		while (k--) {
			char c;
			int a;
			cin >> c >> a;
			if (c == 'I')
				ms.insert(a);
			else if (c == 'D') {
				if (ms.size() == 0) continue;
				if (a == -1)
					ms.erase(ms.begin());
				else
					ms.erase(--ms.end());
			}
		}
		if (ms.size() == 0) cout << "EMPTY\n";
		else cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
	}
	return 0;
}