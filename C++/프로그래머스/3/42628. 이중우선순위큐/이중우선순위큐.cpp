#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> vt;
    for(auto st: operations){
        stringstream ss(st);
        char s;
        int n;
        ss >> s >> n;
        if(s == 'I'){
            vt.push_back(n);
            sort(vt.begin(), vt.end());
        }
        else if (s=='D'){
            if(vt.size() == 0 ) continue;
            if (n == 1)
                vt.erase(vt.begin()+int(vt.size())-1);
            else 
                vt.erase(vt.begin());
            sort(vt.begin(), vt.end());
        }
    }
    if(vt.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(vt[vt.size()-1]);
        answer.push_back(vt[0]);
    }
    return answer;
}