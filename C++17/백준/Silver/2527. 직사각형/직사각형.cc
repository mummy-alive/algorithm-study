#include<iostream>
using namespace std;
int a1[5], b1[5], a2[5], b2[5];
char f() {
	if (a1[1] < a2[0] || b1[1] < b2[0] || a2[1] < a1[0] || b2[1] < b1[0])
		return 'd';
	int cnt = 0;
	if ((a1[1] == a2[0]) && (b1[1] == b2[0]))
		return 'c';
	if ((a1[1] == a2[0]) && (b1[0] == b2[1]))
		return 'c';
	if ((a2[1] == a1[0]) && (b2[1] == b1[0]))
		return 'c';
	if ((a2[1] == a1[0]) && (b2[0] == b1[1]))
		return 'c';
	if (a1[1] == a2[0] || b1[1] == b2[0] || a2[1] == a1[0] || b2[1] == b1[0])
		return 'b';
	return 'a';
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++)
			cin >> a1[j] >> b1[j];
		for (int j = 0; j < 2; j++)
			cin >> a2[j] >> b2[j];
		cout << f()<<'\n';
	}
	return 0;
}