#include <iostream>
using namespace std;

int gcd(int m,int n) {
	if (m % n == 0)
		return n;
	return gcd(n, m % n);
}
int main() {
	int m, n;
	cin >> m >> n;
	if (m >= n) {
		cout << gcd(m, n) << endl;
	}
	else
		cout << gcd(n, m) << endl;
}