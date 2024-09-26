#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> mt;
    for(auto x: operations){
        stringstream ss(x);
        char ch;
        int p;
        ss >> ch >> p;
        if(ch=='I') {
            mt.insert(p);
        }   
        else {
            if(mt.size()==0) continue;
            if(p==1) {
                mt.erase(--mt.end());
            }
            else {
                mt.erase(mt.begin());
            }
        }
    }
    if(mt.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*mt.rbegin());
        answer.push_back(*mt.begin());
    }
    return answer;
}