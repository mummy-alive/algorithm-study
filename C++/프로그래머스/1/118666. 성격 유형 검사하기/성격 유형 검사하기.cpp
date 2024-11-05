#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> mp;
    int n = survey.size();
    for(int i=0; i<n; i++) {
        string st = survey[i];
        if(choices[i] < 4) mp[st[0]]+= 4 - choices[i];
        else mp[st[1]] += choices[i] - 4;
    }
    if(mp['R'] >= mp['T']) answer = answer + 'R';
    else answer = answer + 'T';
    if(mp['C'] >= mp['F']) answer = answer + 'C';
    else answer = answer + 'F';
    if(mp['J'] >= mp['M']) answer = answer + 'J';
    else answer = answer + 'M';
    if(mp['A'] >= mp['N']) answer = answer + 'A';
    else answer = answer + 'N';
    return answer;
}