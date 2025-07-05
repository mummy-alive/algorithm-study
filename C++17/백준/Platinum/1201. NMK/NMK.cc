#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
vector<int> vec;
vector<bool> check;

void init() {
    cin >> n >> m >> k;
    vec.resize(m * k);
    check.resize(n + 1, false);
    check[0] = true;
    
    for(int i = 1; i <= m; i++) {
        vec[i * k - 1] = i;
        check[i] = true;
    }
}
void calc() {
    for(int i = n; i > 0; i--) {
        if(check[i])
            continue;
        int chk = 0;
        int idx = -1;
        for(int j = m * k - 1; j >= 0; j--) {
            if(vec[j] == 0 && chk == 0) {
                chk = 1;
            }
            else if(vec[j] != 0 && chk == 1) {
                idx = j + 1;
                break;
            }
        }
        if(chk == 1 && idx == -1) {
            idx = 0;
        }
        else if(idx == -1) {
            break;
        }  
        for(int j = 0; j < k - 1; j++) 
            if(check[i - j] == false) {
                vec[idx + j] = i - j;
                check[i - j] = true;
            }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    if(m + k - 1 > n || n > m * k) {
        cout << -1;
        return 0;
    }
    if(k == 1 && n == m) {
        for(int i = 1; i <= n; i++)
            cout << i << ' ';
        return 0;
    }  
    calc();    
    for(auto v : vec) {
        if(v != 0) 
            cout << v << ' ';
    }
    return 0;
}