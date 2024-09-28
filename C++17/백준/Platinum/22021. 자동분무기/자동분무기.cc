#include<iostream>
#define SZ 8
using namespace std;
int m = 50;
int main() {
	cin >> m;
	int arr[15][15], sum[15][15] = { 0 }, x[15][15];
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++) {
			cin >> arr[i][j];
			x[i][j] = m;
		}
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			for (int k = 0; k < SZ; k++)
				sum[i][j] += arr[i][k] + arr[k][j];
			sum[i][j] -= arr[i][j];
			if (sum[i][j] % 2 != m % 2) {
				for (int k = 0; k < SZ; k++) {
					x[k][j]++;
					x[i][k]++;
				}
				x[i][j]--;
			}
		}
	}
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (sum[i][j] % 2 == m % 2) {
				cout << ". ";
				continue;
			}
			int par = 0;
			for (int k = 0; k < SZ; k++) 
				par += x[i][k] + x[k][j];
			par -= x[i][j];
			cout << ((par - sum[i][j]) % 4 == 2 ? '-' : '+') << ' ';
		}
		cout << '\n';
	}
	return 0;
}