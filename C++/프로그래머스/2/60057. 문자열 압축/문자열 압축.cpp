#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int n = s.size();
    for(int i=1; i<=n/2;i++) {
        int cnt = 0;
        int tmp=1;
        string prev= "";
        for(int j=0; j <= n; j+=i) {
            string par = s.substr(j, i);
            if(par == prev){
                tmp++;
                continue;
            }
            if(tmp > 1){
                cnt += (int)log10(tmp) + 1;
            }
            tmp = 1;
            cnt += min(i, n-j);
            prev = par;
        }
        answer = min(answer, cnt);
    }
    return answer;
}