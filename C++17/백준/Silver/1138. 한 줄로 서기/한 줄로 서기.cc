#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[15], sum[15], ans[15];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int p = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] == sum[j]) {
				p = j;
				break;
			}
		}
		ans[p] = i + 1;
		sum[p] = -1;
		for (int j = p + 1; j < n; j++)
			sum[j]--;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	return 0;
}