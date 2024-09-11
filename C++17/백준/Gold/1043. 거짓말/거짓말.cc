#include<iostream>
#include<vector>
using namespace std;
int n, m, num_tr, arr[55], sum, tr[55];
bool check[55];
vector<int>vt[55];
int fnd(int p) {
	if (arr[p] == p)
	{
		return p;
	}
	return arr[p] = fnd(arr[p]);
}

int main() {
	cin >> n >> m >> num_tr;
	sum = m;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < num_tr; i++)
	{
		cin >> tr[i];
	}

	for(int k = 0; k < m; k++)
	{
		int num, par, root;
		cin >> num;
		for(int i=0; i<num; i++)
		{	
			cin >> par;
			vt[k].push_back(par);
			if (!i) root = fnd(par);
			else
			{
				arr[fnd(par)] = root;
			}
		}
	}
	for (int i = 0; i<num_tr; i++)
	{
		check[fnd(tr[i])] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (auto x : vt[i])
		{
			if (check[fnd(x)] == 1)
			{
				sum--;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}