#include <string>
#include <vector>
#include<queue>
#include<cstring>
#define SZ 1000005
using namespace std;
vector<int> vt[SZ];
vector<int> answer;

int ind[SZ] = {0}, oud[SZ] = {0};
void bfs(int v){
    bool idx[SZ] = {0};
    queue<int> qu;
    qu.push(v);
    while(!qu.empty()){
        int p = qu.front(); qu.pop();
        if(vt[p].size() == 0) {
            answer[2]++;
            return;
        }
        if(vt[p].size() == 2){
            answer[3]++;
            return;
        }
        if(idx[p]){
            answer[1]++;
            return;
        }
        idx[p]=1;
        for(auto x: vt[p])
            qu.push(x);
    }
}
vector<int> solution(vector<vector<int>> edges) {
    int st=0;
    for(auto x:edges){
        vt[x[0]].push_back(x[1]);
        ind[x[1]]++, oud[x[0]]++;
    }
    for(int i=1; i<SZ; i++){
        if(!ind[i] && oud[i] > 1){
            st =i; break;
        }
    }
    answer.push_back(st);
    for(int i=0; i<3; i++)
        answer.push_back(0);
    for(auto x:vt[st]){
        bfs(x);
    }
    return answer;
}