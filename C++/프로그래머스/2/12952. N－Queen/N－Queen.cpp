#include <string>
#include <vector>

using namespace std;
int n, ans;
bool idx[15][15] = {0};
void f(int r, int c){
    for(int i=r-1; i>=0; i--)
        if(idx[i][c]) return;
    for(int i=1; r-i >=0 && c-i>=0; i++)
        if(idx[r-i][c-i]) return;
    for(int i=1; r-i >=0 && c+i <n; i++)
        if(idx[r-i][c+i]) return;
    if(r==n-1) {
        ans++;
        return;
    }
    for(int i=0; i<n; i++){
        idx[r+1][i] = 1;
        f(r+1, i);
        idx[r+1][i] = 0;
    }
}

int solution(int N) {
    int answer = 0;
    n = N;
    for(int i=0; i<n; i++){
        idx[0][i]=1;
        f(0,i);
        idx[0][i]=0;
    }
    return ans;
}