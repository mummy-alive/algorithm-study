#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool idx[15][15] = {0};

bool chk(int sz, int r, int c){
    for(int i=r-1; i>0; i--){
        if(idx[i][c])
            return 0;
    }
    for(int i=1; i<r; i++){
        if(c+i > sz) break;
        if(idx[r-i][c+i])
            return 0;
    }
    for(int i=1; i<r; i++){
        if(c-i <= 0) break;
        if(idx[r-i][c-i])
            return 0;
    }
    return true;
}

int f(int sz, int r, int c) {
    if(r >= sz) return 1;
    int sum = 0;
    for(int j=1; j<=sz; j++){
        if(chk(sz, r+1, j)) {
            idx[r+1][j] = 1;
            sum += f(sz, r + 1, j);
            idx[r+1][j] = 0;
        }
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    for(int j=1; j<=n; j++){
        idx[1][j] = 1;
        answer += f(n, 1, j);
        idx[1][j] = 0;
    }
    return answer;
}