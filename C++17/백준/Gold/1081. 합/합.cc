#include<iostream>
#define LLONG_MAX 2e10
using namespace std;
typedef long long LL;

LL f(LL n) {
    if (n < 0) return 0;
    LL res = 0;

    for (LL pos = 1; pos <= n; pos *= 10) {
        LL higher = n / (pos * 10);
        LL cur = (n / pos) % 10;
        LL lower = n % pos;

        res += higher * 45 * pos;

        res += (cur * (cur - 1) / 2) * pos;
        res += cur * (lower + 1);
        if (pos > (LLONG_MAX / 10)) break;
    }
    return res;
}

int main() {
    LL l, u;
    cin >> l >> u;
    cout << f(u) - f(l - 1);
    return 0;
}
