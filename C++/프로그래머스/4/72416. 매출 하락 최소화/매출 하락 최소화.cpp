#include <string>
#include <vector>
#include <cstring>
#define SZ 300005
using namespace std;
int dp[SZ][2];
vector<int> cost;
vector<int> vt[SZ];

void dfs(int v){
    bool leaf_node = 1;
    for(auto x: vt[v]){
        leaf_node = 0;
        dfs(x);
    }
    if(leaf_node){
        dp[v][0] = 0;
        dp[v][1] = cost[v-1];
        return;
    }
    int sum = 0;
    int mn = 2e9;
    bool flg= 1;
    for(auto x: vt[v]){
        sum += min(dp[x][0], dp[x][1]);
        if(dp[x][0]>=dp[x][1]) flg=0;
        mn = min(mn, dp[x][1] - dp[x][0]);
    }
    dp[v][1] = cost[v-1] + sum;
    if(!flg) dp[v][0] = sum;
    else dp[v][0] = sum + mn;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    cost = sales;
    for(auto x: links){
        vt[x[0]].push_back(x[1]);
    }
    dfs(1);
    answer = min(dp[1][0], dp[1][1]);
    return answer;
}