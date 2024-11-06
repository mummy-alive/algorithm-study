#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> mp;
    map<string, int> sum;
    for(auto x: report){
        stringstream ss(x); string fr, to;
        ss >> fr >> to;
            
        if(mp[fr].count(to)) continue;
        mp[fr].insert(to);
        sum[to]++;
    }
    set<string> li;
    for(auto x: id_list){
        if(sum[x] >=k) li.insert(x);
    }
    for(auto x:id_list){
        int cnt=0;
        for(auto y: mp[x]){
            if(li.count(y)) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}