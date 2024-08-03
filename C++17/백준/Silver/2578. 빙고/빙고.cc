#include<iostream>
#include<set>
using namespace std;
int check[3][10] = { 0 }, check_cross[2] = { 0 }, bingo;
set<int> c[6], l[6], cross1, cross2;
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int a;
			cin >> a; //input 입력
			c[j].insert(a);
			l[i].insert(a);
			if (i == j)
				cross1.insert(a);
			if (i + j == 4)
				cross2.insert(a);
		}
	}
	for (int i = 0; i < 25; i++) {
		int a;
		cin >> a; 
		for (int k = 0; k < 5; k++) {
			if (c[k].count(a) > 0) { 
				check[0][k]++;
				if (check[0][k] == 5) bingo++;
			}
			if (l[k].count(a) > 0) {
				check[1][k]++;
				if (check[1][k] == 5) bingo++;
			}
		}
		if (cross1.count(a) > 0) {
			check_cross[0]++;
			if (check_cross[0] >= 5) {
				check_cross[0] = 0;
				bingo++;
			}
		}
		if (cross2.count(a) > 0) {
			check_cross[1]++;
			if (check_cross[1] >= 5) {
				check_cross[1] = 0;
				bingo++;
			}
		}
		if (bingo >= 3) {
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}