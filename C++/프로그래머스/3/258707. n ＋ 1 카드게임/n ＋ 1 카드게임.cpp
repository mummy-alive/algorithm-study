#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size(), cnt = 0;
    set<int> st, box;
    for(int i=0; i<n/3; i++) st.insert(cards[i]);
    for(int i=n/3; i<n; i+=2) {
        cnt++;
        if(st.count(n+1-cards[i]) && coin > 0) {
            coin--;
            st.insert(cards[i]);
        } else box.insert(cards[i]);
        if(st.count(n+1-cards[i+1]) && coin > 0){
            coin--;
            st.insert(cards[i+1]);
        } else box.insert(cards[i+1]);
        bool flg=0;
        for(auto x: st) {
            if(st.count(n+1-x)) {
                flg=1;
                st.erase(x); st.erase(n+1-x);
                break;
            }
        }   
        if(!flg) {
            if(coin <= 0) return cnt;
            bool check = 0;
            for(auto x: box) {
                if(st.count(n+1-x)) {
                    check=1;
                    box.erase(x), st.erase(n+1-x);
                    coin--;
                    break;
                }
            }
            if(!check) {
                if(coin < 2) return cnt;
                for(auto x: box) {
                    if(box.count(n+1-x)) {
                        coin-=2;
                        check=1;
                        box.erase(x), box.erase(n+1-x);
                        break;
                    }
                }
            }
            if(!check) return cnt;
        }
    }
    return cnt+1;
}