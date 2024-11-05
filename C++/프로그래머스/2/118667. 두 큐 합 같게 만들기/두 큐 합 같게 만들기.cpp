#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long s1 = 0, s2 = 0, sum = 0;
    int n = int(queue1.size()) + int(queue2.size());
    queue<int> q1, q2;
    for(auto x: queue1) {
        q1.push(x);
        s1 += x;
    }
    for(auto x: queue2) {
        q2.push(x);
        s2 += x;
    }
    /*sum = s1 + s2;
    if(sum % 2) return -1;*/
    for(int i=0; i<=2 * n; i++) {
        if(s1 == s2) return i;
        if(s1 > s2) {
            long long p = q1.front(); q1.pop();
            s1 -= p; s2 += p;
            q2.push(p);
        }
        else {
            long long p = q2.front(); q2.pop();
            s2 -= p; s1 += p;
            q1.push(p);
        }
    }
    return -1;
}