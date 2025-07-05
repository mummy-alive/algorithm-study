#include<iostream>
#include<vector>
#include<algorithm>
#define MOD int(1e9+7)
using namespace std;
typedef long long LL;

LL p(LL a, LL n) {
    if (n == 0) 
        return 1;
    if (n == 1) 
        return a;
    LL x = p(a, n/2);
    if (n % 2) 
        return x*x*a%MOD;
    else return x*x%MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<LL> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (p(2, i)*v[i] - p(2, n-1-i)*v[i]);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}