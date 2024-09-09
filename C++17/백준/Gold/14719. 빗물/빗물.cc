#include<iostream>
using namespace std;
int h, w, arr[505], lt[505], rt[505], ans;
int main() {
	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		cin >> arr[i];
		lt[i] = max(lt[i - 1], arr[i]);
	}
	for (int i = w; i >= 1; i--)
		rt[i] = max(rt[i + 1], arr[i]);
	
	for (int i = 1; i <= w; i++) {
		ans += min(lt[i], rt[i]) - arr[i];
	}
	cout << ans;
	return 0;
}