#include <iostream>
using namespace std;
typedef long long LL;
LL n, m, ans;
LL fr[6005], to[6005], wt[6005], dist[505];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (LL i = 2; i <= n; i++)
		dist[i] = 1e9;
	for (LL i = 0; i < m; i++) {
		cin >> fr[i] >> to[i] >> wt[i];
	}
	LL last = 0;
	for (LL j = 0; j < n; j++) {
		for (LL i = 0; i < m; i++) {
			if ((dist[fr[i]] < 1e9) && (dist[to[i]] > dist[fr[i]] + wt[i])) {
				dist[to[i]] = dist[fr[i]] + wt[i];
				last = j;
			}
		}
	}
	if (last == n - 1) {
		cout << -1;
		return 0;
	}
	for (LL i = 2; i <= n; i++)
		cout << (dist[i] >= 1e9 ? -1 : dist[i]) << '\n';
	return 0;
}