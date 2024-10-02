#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[55];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int k = 0; k < n; k++) {
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] + 1 != arr[i]) continue;
			int p = upper_bound(arr, arr + n, arr[i]) - arr;
			if (p < n)
				swap(arr[i], arr[p]);
			else {
				swap(arr[i - 1], arr[i]);
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}