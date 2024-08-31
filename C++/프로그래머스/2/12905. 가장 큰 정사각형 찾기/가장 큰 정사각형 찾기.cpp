#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int sum[1005][1005]={0};
    int r = board.size();
    int c = board[0].size();
    
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c;j++){
            if(board[i-1][j-1]) answer= 1;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + board[i-1][j-1];
        }
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(!board[i-1][j-1]) continue;
            for(int k=answer; k <= min(r, c); k++) {
                if (i+k-1 > r || j+k-1 > c) break;
                int par = sum[i+k-1][j+k-1] - sum[i+k-1][j-1] - sum[i-1][j+k-1] + sum[i-1][j-1];
                if (par == k*k)
                    answer = max(answer, k);
            }
        }
    }
    
    return answer*answer;
}