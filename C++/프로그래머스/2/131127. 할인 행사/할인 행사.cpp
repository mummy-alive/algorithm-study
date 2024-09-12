#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wish;
    for(int i=0; i<want.size(); i++){
        wish[want[i]] = number[i];
    }
    for(int i=0; i<discount.size() - 9; i++){
        map<string, int> mp;
        for(int j=0; j<10; j++)
            mp[discount[i+j]]++;
        bool flg=0;
        for(auto x: want){
            if(mp[x] < wish[x]){
                flg =1;
                break;
            }
        }
        if(!flg) answer++;
    }
    return answer;
    
    
    
    
    /*int answer = 0;
    map<string, int> mp;
    set<string> st;
    int dis[100005][15] = {0};
    for(int i=0; i<want.size(); i++){
        st.insert(want[i]);
        mp[want[i]] = i;
    }
    int day = 1;
    for(auto x: discount){
        if(!st.count(x)) continue;
        for(int i=0; i<want.size(); i++){
            dis[day][i] = dis[day-1][i];
        }
        dis[day][mp[x]]++;
        day++;
    }
    for(int i=1; i+9 <= discount.size(); i++){
        bool flg =0;
        for(int j=0; j<want.size(); j++){
            if(dis[i+9][j] - dis[i-1][j] < number[j]){
                flg = 1;
                break;
            }
        }
        if(!flg) answer++;
    }
    return answer;*/
}