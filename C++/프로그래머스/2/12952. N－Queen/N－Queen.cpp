#include <string>
#include <vector>

using namespace std;
int ans = 0;
int sz;
int col[15];
bool arr[15][15] = {0};

bool chk(int k){
    for(int i=0; i<k; i++){
        if(col[k] == col[i] || k-i == abs(col[k] - col[i]))
            return false;
    }    
    return true;
}

void f(int k){
    if(k == sz) {
        ans++;
        return;
    }
    for(int i=0; i<sz; i++) {
        col[k] = i;
        if(chk(k)) {
            f(k+1);
        }
    }
}

int solution(int n) {
    sz = n;
    f(0);
    return ans;
}