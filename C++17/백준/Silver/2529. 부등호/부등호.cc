#include<iostream>
#include<cstring>
using namespace std;
int k, par[15], mx[15], mn[15];
bool check[15];
char ch[15];
void mxncheck() {
	for (int i = 0; i <= k; i++) {
		if (par[i] < mx[i]) break;
		if (par[i] > mx[i]) {
			for (int j = 0; j <= k; j++) {
				mx[j] = par[j];
			}
			break;
		}
	}
	for (int i = 0; i <= k; i++) {
		if (par[i] > mn[i]) break;
		if (par[i] < mn[i]) {
			for (int j = 0; j <= k; j++) {
				mn[j] = par[j];
			}
			break;
		}
	}
}
void f(int r, int n) {
	if (r >= k) {
		mxncheck();
		return;
	}
	if (ch[r] == '>') {
		for (int i = 0; i < n; i++) {
			if (check[i]) continue;
			check[i] = 1;
			par[r + 1] = i;
			f(r + 1, i);
			check[i] = 0;
		}
	}
	else if (ch[r] == '<') {
		for (int i = n+1; i < 10; i++) {
			if (check[i]) continue;
			check[i] = 1;
			par[r + 1] = i;
			f(r + 1, i);
			check[i] = 0;
		}
	}

}
int main() {
	memset(mn, 0x3f, sizeof(mn));
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> ch[i];
	for (int i = 0; i < 10; i++) {
		par[0] = i;
		check[i] = 1;
		f(0, i);
		check[i] = 0;
	}
	for (int i = 0; i <= k; i++)
		cout << mx[i];
	cout << '\n';
	for (int i = 0; i <= k; i++)
		cout << mn[i];
	cout << '\n';
	return 0;
}