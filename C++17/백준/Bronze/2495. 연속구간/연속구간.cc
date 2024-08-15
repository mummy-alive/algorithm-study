#include<iostream>
using namespace std;
int main() {
	string st;
	while (cin >> st) {
		int cnt = 1, mx = 1;
		for (int i = 1; i < st.size(); i++) {
			if (st[i] == st[i - 1]) {
				cnt++;
				mx = max(mx, cnt);
			}
			else
				cnt = 1;
		}
		cout << mx<<"\n";
	}
	return 0;
}