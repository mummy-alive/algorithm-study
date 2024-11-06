#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0, m = board.size(), n = board[0].size();
    int sum[1005][1005]={0}, arr[1005][1005] = {0};
    for(auto x: skill){
        int ty = (x[0] == 1 ? -1 : 1);
        int sr = x[1], sc = x[2], er = x[3], ec = x[4];
        int dp = x[5];
        sum[er+1][ec+1] += dp*ty;
        sum[sr][ec+1] -= dp*ty;
        sum[er+1][sc] -= dp*ty;
        sum[sr][sc] += dp*ty;
    }
    int par = 0;
    for(int i=0; i<=m; i++)
        for(int j=0; j<n; j++)
            sum[i][j+1] += sum[i][j];

    for(int j=0; j<=n; j++)
        for(int i=0; i<m; i++)
            sum[i+1][j] += sum[i][j];
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(board[i][j] + sum[i][j] > 0) answer++;

    return answer;
}