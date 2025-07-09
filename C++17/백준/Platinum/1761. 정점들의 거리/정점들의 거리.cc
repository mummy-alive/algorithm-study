#include<iostream>
#include<vector>

#define inf INT_MAX
using namespace std;
int n, m, parent[100005][25], depth[100005],value[100005], a, b, c;
vector<pair<int,int>>v[100005];
void dfs(int x, int par) {
    depth[x] = depth[par] + 1;
        for (auto nxt : v[x]) {
            if (nxt.first == par)continue;
            parent[nxt.first][0] = x;
            value[nxt.first] = nxt.second+value[x];
            dfs(nxt.first, x);
        }
}

int lca(int x, int y) {
    if (depth[x] > depth[y])swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent[y][i];
        }
    if (x == y)
        return x; 
    for (int i = 20; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int cnt=0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b>>c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    dfs(1, 0);
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << (value[a] + value[b]) - 2 * value[lca(a, b)] << '\n';
    }
    return 0;
}
