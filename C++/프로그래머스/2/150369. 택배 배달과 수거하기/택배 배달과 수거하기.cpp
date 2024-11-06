#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dsum = 0, psum = 0;
    for(int i=n-1; i>=0; i--){
        dsum += deliveries[i];
        psum += pickups[i];
        while (dsum > 0 || psum > 0) {
            answer += (i+1)*2;
            dsum -= cap;
            psum -= cap;
        }
    }
    return answer;
}