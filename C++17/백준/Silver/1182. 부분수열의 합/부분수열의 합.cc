#include<iostream>
using namespace std;
typedef long long LL;
LL n, s, cnt;
LL arr[25];
void f(int p, int sum, bool flg) {
    if (flg && (sum == s)) {
        cnt++;
        flg = 0;
    }
    if (p >= n)
        return;
    for (int i = 0; i < 2; i++)
        f(p + 1, sum + arr[p] * i, flg || i);
}
int main() {
    cin >> n >> s;
    for (LL i = 0; i < n; i++) {
        cin >> arr[i];
    }
    f(0, 0, 0);
    cout << cnt;
}
