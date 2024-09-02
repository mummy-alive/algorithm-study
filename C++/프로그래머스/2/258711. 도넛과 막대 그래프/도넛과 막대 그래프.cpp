#include <string>
#include <iostream>
#include <queue>
#include <vector>
#define SZ 1000005
using namespace std;
int donut, bar, eight;
vector<int> vt[SZ];
bool idx[SZ];

void bfs(int v){
    queue<int> qu;
    qu.push(v);
    while (!qu.empty()) {
        int k = qu.front();
//        cout<<k<<"pops\n";
        qu.pop();
        if(vt[k].size() == 2){
            eight++;
            return;
        }
        if (idx[k]) {
            donut++;
            return;
        }
        idx[k] = 1;
        for(auto x: vt[k])
            qu.push(x);
    }
//    cout<<bar<<'\n';
    bar++;
}


void f(int v) {
    bfs(v);
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    int ind[SZ]={0}, oud[SZ] ={0};
    int n = edges.size();
    for(int i=0; i<n; i++){
        int u = edges[i][0], v = edges[i][1];
        vt[u].push_back(v);
        ind[v]++;
        oud[u]++;
    }
    int start=0;
    for(int i=1; i<SZ; i++){
        if((ind[i] == 0) && (oud[i] > 1)){
            start = i;
            break;
        }
    }
    answer.push_back(start);
    for (auto x: vt[start]){
        f(x);
//        cout<<x<<" starts\n";
    }
    answer.push_back(donut);
    answer.push_back(bar);
    answer.push_back(eight);
    return answer;
}