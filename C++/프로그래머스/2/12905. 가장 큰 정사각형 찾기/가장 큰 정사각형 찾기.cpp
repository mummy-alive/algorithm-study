#include<vector>
using namespace std;
int r, c;
int arr[1005][1005] = {0};
int f(int k){
    for(int i=k; i<=r; i++){
        for(int j=k; j<=c; j++){
            int par = arr[i][j] - arr[i][j-k] - arr[i-k][j] + arr[i-k][j-k];
            if (par == k*k)
                return true;
         }
    }    
    return false;
}

int solution(vector<vector<int>> board) {
    r = board.size(), c = board[0].size();
    for(int i=1;i<=r; i++){
        for(int j=1; j<=c; j++){
            arr[i][j] = arr[i-1][j]+arr[i][j-1] - arr[i-1][j-1] + board[i-1][j-1];
        }
    }
    for(int k=1; ;k++){
        if(!f(k))
            return (k-1)*(k-1);
    }
    return 0;
}