#include <vector>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
bool chk[105][105] = { 0 };
int m_sz, n_sz;
int dr[] = {1, -1, 0, 0}, dc[] ={0, 0, 1, -1};
vector<vector<int>> pic;
/*
int bfs(int r, int c){
    queue<pair<int,int>> qu;
    qu.push({r, c});
    int sum=0;
    while(!qu.empty()){
        int p = qu.front().first;
        int q = qu.front().second;
        qu.pop();
        if(p < 0 || p >= m_sz || q< 0 || q>= n_sz) continue;
        if(chk[p][q] || !pic[p][q]) continue;
        chk[p][q] =1;
        sum++;
        for(int i=0; i<4; i++)
            qu.push({p+dr[i] , q+dc[i]});
    }
    return sum;
}*/

int dfs(int color, int r, int c){
    if(chk[r][c] || pic[r][c] != color) return 0;
    chk[r][c] = 1;
    int sum = 1;
    for(int i=0; i<4; i++){
        int rr = r+dr[i], cc = c+dc[i];
        if(rr<0 || rr >= m_sz ||cc < 0 || cc >= n_sz)
            continue;
        sum += dfs(color, rr, cc);
    }
    return sum;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(chk, 0, sizeof(chk));
    int number_of_area = 0;
    int cnt=0, mx=0;
    pic = picture;
    m_sz = m; n_sz=n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(chk[i][j] || !picture[i][j]) continue;
            mx = max(mx , dfs(picture[i][j], i, j));
            //mx = max(mx, bfs(picture[i][j], i, j));
            cnt++;
        }
    }
    vector<int> answer(2);
    answer[0] = cnt;
    answer[1] = mx;
    cout<<cnt<<", "<<mx;
    return answer;
}