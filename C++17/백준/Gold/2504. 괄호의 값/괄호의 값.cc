#include<iostream>
#include<stack>
using namespace std;
int ans[35];
string s;
stack<char> st;
void f(int k) {
	int sz = st.size();
	if (ans[sz] == 0) {
		ans[sz] = k;
	}
	else {
		ans[sz] *= k;
	}
	st.pop();
	ans[sz - 1] += ans[sz];
	ans[sz] = 0;
}

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (s[i] == ')' && !st.empty() && st.top() == '(') {
			f(2);
		}
		else if (s[i] == ']' && !st.empty() && st.top() == '[') {
			f(3);
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << ans[0];
	return 0;
}