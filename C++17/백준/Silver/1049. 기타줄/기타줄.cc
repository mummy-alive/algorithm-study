#include<iostream>
#include<algorithm>
using namespace std;
int n, m, ans = 2e9;
int six[55], sg[55];

int main() {
    cin >> n >> m;
    int dn = 1e9, sn = 1e9;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dn = min(dn, a);
        sn = min(sn, b);
    }
    for (int i = 0; i <= n / 6; i++)
        ans = min(ans, i * dn + (n - i * 6) * sn);
    ans = min(ans, (n / 6 + 1) * dn);
    cout << ans;
    return 0;
}