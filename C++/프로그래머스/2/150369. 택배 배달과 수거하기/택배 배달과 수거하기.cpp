#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dsum=0, psum=0;
    for(long long i=n-1; i>=0; i--){
        int cnt=0;
        dsum += deliveries[i]; psum += pickups[i];
        while(dsum>0 || psum>0) {
            dsum -= cap;
            psum -= cap;
            cnt++;
        }
        answer += (i+1) * 2 * cnt;
    }
    return answer;
}