#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[1005], ln, lt[1005], rt[1005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, h;
		cin >> l >> h;
		arr[l] = h;
		ln = max(ln, l);
	}
	for (int i = 1; i <= ln; i++) 
		lt[i] = max(lt[i - 1], arr[i]);
	for (int i = ln; i >= 0; i--) 
		rt[i] = max(rt[i + 1], arr[i]);

	int sum = 0;
	for (int i = 1; i <= ln; i++)
		sum += min(lt[i], rt[i]);
	cout << sum;
	return 0;
}