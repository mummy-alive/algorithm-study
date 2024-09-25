#include <string>
#include<stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    stack<int> st[105];
    for(int j=0  ; j<n; j++){
        for(int i=n-1; i>=0; i--){
            if(board[i][j])
            st[j].push(board[i][j]);
        }
    }
    stack<int> par;
    for(auto x: moves){
        x--;
        if(st[x].empty()) continue;
        int p = st[x].top();
        st[x].pop();
        if(!par.empty() && par.top() == p){
            answer+=2;
            par.pop();
        }
        else par.push(p);
    }
    return answer;
}