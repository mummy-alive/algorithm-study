#include <string>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

int solution(string s) {
   // s = "abababababababababababababababababababab";
    int n = s.size();
    int answer = n ;
    bool flg = 0;
    for(int i=1; i<=n/2; i++) {
        int cnt = 0;
        string prev = "";
        int tmp = 1;
        for(int j=0; j<n; j+=i) {
            string par = s.substr(j, i);
            if(par == prev){
                tmp++;
                continue;
            }
            if(tmp > 1){
                //cout<<cnt<<' '<<(int)log10(tmp) + 1<<'\n';
                cnt += (int)log10(tmp) + 1;
            }
            tmp = 1;
            cnt += min(i, n-j);
            prev = par;
            flg = 0;
        }
        if(tmp > 1){
            //cout<<cnt<<' '<<(int)log10(tmp) + 1<<'\n';
            cnt += (int)log10(tmp) + 1;
        }
        //cout<<i<<": "<<cnt<<'\n';
        answer = min(answer, cnt);
    }
    return answer;
}