#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, mx = 0, arr[1005], sz[1005];
	vector<int> fv, rv;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		int p = lower_bound(fv.begin(), fv.end(), arr[i]) - fv.begin();
		if (p == fv.size()) fv.push_back(arr[i]);
		else fv[p] = arr[i];
		sz[i] = fv.size();
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int p = lower_bound(rv.begin(), rv.end(), arr[i]) - rv.begin();
		if (p == rv.size()) rv.push_back(arr[i]);
		else rv[p] = arr[i];
		sz[i] += rv.size() - 1;
		mx = max(mx, sz[i]);
	}
	cout << mx;
	return 0;
}