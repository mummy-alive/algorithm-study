#include<iostream>
#include<algorithm>
using namespace std;
int ch[30];
char ans[55];
string st;
int main() {
	cin >> st;
	int n = st.size();
	for (int i = 0; i < n; i++) {
		ch[st[i] - 'A']++;
	}
	int p = 0;
	for (int i = 0; i < 26; i++) {
		if (ch[i] % 2) {
			if ((n % 2) && !ans[n / 2]) {
				ch[i]--;
				ans[n / 2] = char(i + 'A');
			}
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < ch[i]; j += 2) {
			ans[p] = (char)(i + 'A');
			ans[n - 1 - p] = (char(i + 'A'));
			p++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	return 0;
}