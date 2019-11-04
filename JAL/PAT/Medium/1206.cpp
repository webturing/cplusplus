#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	b -= a;
	b = (b + 50) / 100;
	int h, m, s;
	h = (b / 3600)%24;
	b %= 3600;
	m = b / 60;
	s = b % 60;
	cout << h << ":" << m << ":" << s << endl;
	return 0;
}