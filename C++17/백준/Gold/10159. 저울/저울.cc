#include <cstdio>
int n, m, a, b, s, ans;
bool d[105][105], e[105][105];
int main() {
	int i, j, k;
	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d", &a, &b);
		d[a][b] = 1;
		e[b][a] = 1;
	}
	for(k=1; k<=n; k++) for(i=1; i<=n; i++) {
		if(d[i][k])
			for(j=1; j<=n; j++) if(d[k][j]) d[i][j] = 1;
		if(e[i][k])
			for(j=1; j<=n; j++) if(e[k][j]) e[i][j] = 1;
	}
	for(i=1; i<=n; i++) {
		s = 0;
		for(j=1; j<=n; j++) s += d[i][j] + e[i][j];
    	printf("%d\n", n-s-1);
	}
	return 0;
}