#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> mp;
    int arr[55][55] = {0}, gft[55] = {0}, res[55] = {0};
    for(int i=0; i<friends.size(); i++)
        mp[friends[i]] = i;
	for(auto x: gifts) {
		istringstream iss(x);
        string a, b;
		iss >> a >> b;
        arr[mp[a]][mp[b]]++;
        gft[mp[a]]++;
        gft[mp[b]]--;
    }
    for(int p=0; p<friends.size(); p++){
        for(int i=p+1; i<friends.size(); i++){
            if(arr[p][i] == arr[i][p]){
                if(gft[p] > gft[i])
                    res[p]++;
                else if(gft[i] > gft[p])
                    res[i]++;
                else continue;
            }  
            else if(arr[i][p] > arr[p][i]) {
                res[i]++;
            }
            else {
                res[p]++;
            }
        }
    }
    int mx = 0;
    for(int i=0; i<friends.size(); i++){
        if(res[i] > res[mx])
            mx = i;
    }
    answer = res[mx];
    return answer;
    
}