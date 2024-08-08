#include<iostream>
#include<stack>
using namespace std;
string s;
int ans;
stack<bool> st;
int main() {
	cin >> s;
	int sl = s.length();
	for (int i = 0; i < sl; i++) {
		if (s[i] == '(') {
			if (s[i + 1] == ')') {
				ans += st.size();
				i++;
			}
			else
				st.push(1);
		}
		else {
			ans++;
			st.pop();
		}
	}
	cout << ans;
	return 0;
}