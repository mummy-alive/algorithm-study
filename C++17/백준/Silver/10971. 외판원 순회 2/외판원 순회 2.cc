#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[15][15], vil[15], ans = 2e9;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		vil[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) arr[i][j] = 1e8;
		}
	do {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += arr[vil[i]][vil[i + 1]];
		}
		sum += arr[vil[n]][vil[1]];
		ans = min(ans, sum);
	} while (next_permutation(vil + 1, vil + n + 1));
	cout << ans;
	return 0;
}