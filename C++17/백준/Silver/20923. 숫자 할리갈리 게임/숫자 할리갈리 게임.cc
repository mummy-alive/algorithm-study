#include<iostream>
#include<queue>
using namespace std;
int n, m;
deque<int> dd, su;
deque<int> d_gr, s_gr;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dd.push_front(a);
		su.push_front(b);
	}
	for (int i = 0; i < m; i++) {
		if (!(i % 2)) {
			int p = dd.front();
			dd.pop_front();
			d_gr.push_front(p);
		}
		else {
			int p = su.front();
			su.pop_front();
			s_gr.push_front(p);
		}
		if (dd.empty()) {
			cout << "su";
			return 0;
		}
		if (su.empty()) {
			cout << "do";
			return 0;
		}
		if (!d_gr.empty()) {
			if (d_gr.front() == 5) {
				while (!s_gr.empty()) {
					int p = s_gr.back();
					s_gr.pop_back();
					dd.push_back(p);
				}
				while (!d_gr.empty()) {
					int p = d_gr.back();
					d_gr.pop_back();
					dd.push_back(p);
				}
			}
		}
		if (!s_gr.empty()) {
			if (s_gr.front() == 5) {
				while (!s_gr.empty()) {
					int p = s_gr.back();
					s_gr.pop_back();
					dd.push_back(p);
				}
				while (!d_gr.empty()) {
					int p = d_gr.back();
					d_gr.pop_back();
					dd.push_back(p);
				}
			}
		}
		if ((!d_gr.empty() && !s_gr.empty())) {
			if (d_gr.front() + s_gr.front() == 5) {
				while (!d_gr.empty()) {
					int p = d_gr.back();
					d_gr.pop_back();
					su.push_back(p);
				}
				while (!s_gr.empty()) {
					int p = s_gr.back();
					s_gr.pop_back();
					su.push_back(p);
				}
			}
		}
	}
	if (dd.size() >= su.size())
		cout << "do";
	if (dd.size() <= su.size())
		cout << "su";
	return 0;
}