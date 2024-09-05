#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n;
pair<int, int> arr[200005];
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	pq.push(-arr[0].second);
	for (int i = 1; i < n; i++) {
		if (-pq.top() <= arr[i].first)
			pq.pop();
		pq.push(-arr[i].second);
	}
	cout << pq.size();
	return 0;
}