#include<iostream>
#include<queue>
#include<set>
using namespace std;
int n, k, num, t[105];
set<pair<int, int>> st;
char c[105];
bool body[105][105];
deque<pair<int, int>> dq;
int f() {
	dq.push_front({ 1, 1 });
	dq.push_front({ 1, 2 });
	body[1][1] = body[1][2] = 1;
	int a = 0, pt = 0;
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	int d = 0;
	for (int i = 1; ; i++) {
		
		pair<int, int> head = dq.front(), tail = dq.back();
		if (st.count(head)) {
			a++;
			st.erase(head);
		}
		else {
			body[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		if (i == t[pt]) {
			if (c[pt] == 'D')
				d = (d + 1) % 4;
			else d = (d + 4 - 1) % 4;
			pt++;
		}
		head = { head.first + dr[d], head.second + dc[d] };
		if (body[head.first][head.second] || head.first < 1 || head.first > n || head.second < 1 || head.second > n)
			return i;
		dq.push_front(head);
		body[head.first][head.second] = 1;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		st.insert({ x, y });
	}
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> t[i] >> c[i];
	cout << f() + 1;
	return 0;
}