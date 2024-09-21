#include<iostream>
using namespace std;
string st, ans = "";
int cnt[130] = { 0 };
int main() {
	cin >> st;
	int n = st.size();
	for (int i = 0; i < n; i++) 
		cnt[st[i]]++;
	bool flg = 0;
	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i] % 2) {
			if (!(n % 2)) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else {
				if (flg) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}
				flg = 1;
				ans = char(i);
				cnt[i]--;
			}
		}
	}
	for (int i = 'Z'; i >= 'A'; i--) {
		while (cnt[i]) {
			ans = char(i) + ans + char(i);
			cnt[i] -= 2;
		}
	}
	cout << ans;
	return 0;
}