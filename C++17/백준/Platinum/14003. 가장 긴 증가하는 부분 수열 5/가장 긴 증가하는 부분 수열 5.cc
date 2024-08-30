#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define SZ 1000005
using namespace std;
int n, arr[SZ], ln=1, par[SZ], pa2[SZ], track[SZ];
stack<int> st;
vector<int> ans;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    par[0] = -2e9;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(par, par + ln, arr[i]) - par;
        par[pos] = arr[i];
        pa2[pos] = i;
        track[i] = pa2[pos - 1];
        if (pos == ln) {
            ln++;
        }
    }
    ln--;
    cout << ln << '\n';
    int p = pa2[ln];
    while (p > 0) {
        st.push(arr[p]);
        p = track[p];
    }
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}
