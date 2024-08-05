#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, arr1[505], arr2[505], sum;
vector<int> vt1[505], vt2[505];
queue<int> pq;
int fnd(int per, int up) {	//0은 자기보다 작은 사람, 1은 큰 사람
	int rtd = 0;
	pq.push({ per });
	while (!pq.empty())
	{
		int node = pq.front();
		pq.pop();
		if (up)
		{
			for (auto x : vt1[node])
			{
				if (arr1[x] == 1e9)
				{
					arr1[x] = 1;
					rtd++;
					pq.push({ x });
				}
			}
		}
		else
		{
			for (auto x : vt2[node])
			{
				if (arr2[x] == 1e9)
				{
					arr2[x] = 1;
					rtd++;
					pq.push({ x });
				}
			}
		}
	}
	return rtd;	//자기보다 작거나 큰 사람 수 리턴			
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vt1[a].push_back(b);
		vt2[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr1[j] = arr2[j] = 1e9;
			if (i == j) arr1[j] = arr2[j] = 0;
		}
		if (fnd(i, 0) + fnd(i, 1) == n-1)
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}