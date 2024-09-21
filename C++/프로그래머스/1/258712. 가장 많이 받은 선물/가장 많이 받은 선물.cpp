#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> mp;
    int arr[55][55] = {0}, gft[55] = {0}, ans[55] = {0};
    int n = 0;
    for(auto x: friends){
        mp[x] = n;
        n++;
    }
    for(auto x: gifts){
        istringstream iss(x);
        string a, b;
        iss >> a >> b;
        arr[mp[a]][mp[b]]++;
        gft[mp[a]]++;
        gft[mp[b]]--;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i][j] - arr[j][i] != 0){
                if(arr[i][j] > arr[j][i])
                    ans[i]++;
                else ans[j]++;
            }
            else{
                if(gft[i]!=gft[j]){
                    if(gft[i] > gft[j])
                        ans[i]++;
                    else ans[j]++;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
        answer = max(answer, ans[i]);
    
    
    return answer;
}