#include<iostream>
#include<cstring>
#include<ext/rope>
typedef long long LL;
using namespace std;
using namespace __gnu_cxx;  
LL t, ver = 0, dsum=0;
crope rp[50005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	for (LL x=1; x<=t; x++) {
		LL k; string query;
		cin >> k;
		LL p, q, r;
		string st;
		if (k == 1) {
			cin >> p >> st;
            p-=dsum;
            rp[ver + 1] = rp[ver].substr(0, p) + crope(st.c_str()) + rp[ver].substr(p, rp[ver].size() - p);
            ver++;
        }
		else if (k == 2) {
			cin >> p >> q;
            p-=dsum; q-=dsum;
			rp[ver+1] = rp[ver].substr(0, p-1) + rp[ver].substr(p-1+q,  rp[ver].size() - ((p - 1) + q));
    		ver++;
        }
		else {
			cin >> p >> q >> r;
            p-=dsum; q-=dsum; r-=dsum;
            crope out = rp[p].substr(q-1, r);
            for(char ch: out){
                cout<<ch;
                if(ch =='c') dsum++;
            }cout<<'\n';
		}
	}
	return 0;
}