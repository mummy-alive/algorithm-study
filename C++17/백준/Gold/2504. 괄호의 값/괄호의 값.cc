#include<iostream>
#include<stack>
using namespace std;
int ans;
string s;
stack<char> st, op;
int main() {
	cin >> s;
	int par = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			if (s[i-1] == '(') {
				ans += par;
				par /= 2;
				st.pop();
			}
			else {
				par /= 2;
				st.pop();
			}
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			if (s[i-1] == '[') {
				ans += par;
				par /= 3;
				st.pop();
			}
			else {
				par /= 3;
				st.pop();
			}
		}
		else if (s[i] == '(') {
			par *= 2;
			st.push('(');
		}
		else if (s[i] == '[') {
			par *= 3;
			st.push('[');
		}
			
	}
	if (!st.empty()) {
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}