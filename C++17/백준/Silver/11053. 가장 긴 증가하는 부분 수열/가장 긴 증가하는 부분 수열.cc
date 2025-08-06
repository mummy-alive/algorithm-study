#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> vt;
int main() {
	cin >> n;
	while (n--) {
		int k; cin >> k;
		int par = lower_bound(vt.begin(), vt.end(), k) - vt.begin();
		if (par == vt.size())
			vt.push_back(k);
		else
			vt[par] = k;
	}
	cout << vt.size();
	return 0;
}