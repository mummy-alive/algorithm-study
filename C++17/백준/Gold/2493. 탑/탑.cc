#include<iostream>
#include<stack>
using namespace std;
int n;
stack<pair<int, int>> st;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	st.push({ 1e9, 0 });
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a; 
		while (st.top().first <= a )  {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push({ a, i });
	}
	return 0;
}