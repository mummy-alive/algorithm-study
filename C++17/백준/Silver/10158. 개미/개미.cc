#include<iostream>
using namespace std;
int main() {
	int w, h, p, q, t;
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;
	p += t;
	q += t;
	if ((p / w) % 2 == 0)
		p = p % w;
	else
		p = 2 * w - (p % (2 * w));
	if ((q / h) % 2 == 0)
		q = q % h;
	else
		q = 2 * h - (q % (2 * h));
	cout << p <<' '<< q;
	return 0; 
}