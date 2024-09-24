#include <string>
#include <cstring>
#include <queue>
#include <vector>
#define SZ 1000005
using namespace std;
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer, vt[SZ];
    bool idx[SZ] = {0};
    int ind[SZ] = {0}, oud[SZ] = {0}, st = 0;
    memset(idx, 0, sizeof(idx));
    for(auto x: edges){
        vt[x[0]].push_back(x[1]);
        ind[x[1]]++; oud[x[0]]++;
    }
    for(int i=1; i<SZ; i++){
        if(ind[i]==0 && (oud[i] >1)){
            st = i;
            break;
        }
    }
    answer.push_back(st);
    for(int i=0; i<3; i++) answer.push_back(0);

    for(auto x: vt[st]) {
        queue<int> qu;
        qu.push(x);
        while(!qu.empty()){
            int p = qu.front();
            qu.pop();
            if(vt[p].size() < 1){
                answer[2]++;
                break;
            }
            if(vt[p].size() > 1) {
                answer[3]++;
                break;
            }
            if(idx[p]) {
                answer[1]++;
                break;
            }
            idx[p]=1;
            for(auto y: vt[p])
                qu.push(y);
        }
    }
    return answer;
}