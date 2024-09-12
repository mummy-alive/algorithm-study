#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

int cutDate(string dd){
    int y, m, d;
    for(int i=0; i<4; i++){
        y *= 10;
        y += int(dd[i] - '0');
    }
    for(int i=5; i<7; i++){
        m *= 10;
        m += int(dd[i] - '0');
    }
    for(int i=8; i<10; i++){
        d *= 10;
        d += int(dd[i] - '0');
    }
    return y * 12 * 28 + (m-1) * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int t[100], ty, tm, td;
    map<char, int> mp;
    for(auto x: terms){
        stringstream ss(x);
        char a;
        int b;
        ss >> a >> b;
        mp[a] = b;
    }
    int tdate = cutDate(today);
    for(int i=0; i<privacies.size(); i++){
        stringstream ss(privacies[i]);
        string a;
        char b;
        ss >> a >> b;
        int par = cutDate(a);
        par += mp[b] * 28;
        if(par <= tdate)
           answer.push_back(i+1); 
    }
    return answer;
}