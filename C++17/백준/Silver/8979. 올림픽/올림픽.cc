#include<iostream>
#include<algorithm>
using namespace std;
typedef struct PR {
	int g, s, b, con;
} PR;
int n, k;
PR arr[505];
bool cmp(PR x, PR y) {
	if (x.g == y.g) {
		if (x.s == y.s)
			return x.b > y.b;
		return x.s > y.s;
	}
	return x.g > y.g;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i].con >> arr[i].g >> arr[i].s >> arr[i].b;
	sort(arr, arr + n, cmp);
	int r = 1;
	int par = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].con == k) {
			cout << r;
			return 0;
		}
		if (arr[i].g == arr[i + 1].g && arr[i].s == arr[i + 1].s && arr[i].b == arr[i + 1].b) {
			par++;
			continue;
		}
		else {
			r += 1 + par;
			par = 0;
		}
	}
	return 0;
}
