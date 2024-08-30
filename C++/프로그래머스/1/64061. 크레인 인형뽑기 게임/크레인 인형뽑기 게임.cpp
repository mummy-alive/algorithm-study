#include <string>
#include<iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st[105], basket;
    for(int i=board.size()-1; i >= 0; i--) {
        for(int j=0; j<board[i].size() ; j++) {
            if(board[i][j]) st[j].push(board[i][j]);
        } 
    }
    for(auto x: moves){
        x--;
        if(st[x].empty()) continue;
        int p = st[x].top();
        st[x].pop();
        
        if(basket.empty()){
            basket.push(p);
        }
        else if(basket.top() != p) {
            basket.push(p);
        }
        else {
            basket.pop();
            answer += 2;
        }
//        cout<< x << ' ' << basket.top() << endl;
    }
    return answer;
}