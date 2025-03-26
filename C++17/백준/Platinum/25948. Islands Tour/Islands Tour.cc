#include<iostream>
using namespace std;
int n, m, gr, ans;
int nxt[1000005], weight[1000005], group[1000005];
bool start[1000005];
void cyc(int node) {
	if (node == -1) {
		return;
	}
	if (!group[node]) {
		group[node] = gr;
	//	cout << node << '\n';
		cyc(nxt[node]); 
	}
	else if (group[node] == gr) {
		int p = nxt[node], sum = 1;
		while (p != node) {
			// cout << p << ": " << sum << '\n';
			sum++;
			p = nxt[p];
		}
		p = nxt[node];
		weight[node] = sum;
		while (p != node) {
			// cout << p << ": " << sum << '\n';
			weight[p] = sum;
			p = nxt[p];
		}	
		// cout << node << ": " << sum << '\n';

	}
}

int fnd(int node) {
	if (node == -1) return 0;
	if (weight[node]) return weight[node];
	return weight[node] = fnd(nxt[node]) + 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		nxt[i] = -1;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		nxt[u] = v;
	}
	for (int i = 0; i < n; i++) {
		if (!group[i]) {
			gr++;
			cyc(i);
		}
	}
	/*for (int i = 0; i < n; i++)
		cout << group[i] << ' ';
	cout << '\n';*/
	for (int i = 0; i < n; i++) {
		if (!weight[i])
			fnd(i);
	}
	/*for (int i = 0; i < n; i++)
		cout << weight[i] << ' ';*/
	for (int i = 0; i < n; i++)
		ans = max(weight[i], ans);
	cout << ans;
	return 0;
}