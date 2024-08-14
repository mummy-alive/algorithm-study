#include<iostream>
using namespace std;
int n, sum;
int arr[1005], ln, lt[1005], rt[1005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, h;
		cin >> l >> h;
		arr[l] = h;
	}
	for (int i = 1; i <= 1000; i++) 
		lt[i] = max(lt[i - 1], arr[i]);
	for (int i = 1000; i >= 0; i--) {
		rt[i] = max(rt[i + 1], arr[i]);
		sum += min(lt[i], rt[i]);
	}
	cout << sum;
	return 0;
}