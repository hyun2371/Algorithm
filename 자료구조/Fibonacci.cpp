#include <iostream>
using namespace std;
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 2) + fib(n - 1);
}
int fact(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	return n*fact(n - 1);
}
int main() {
	cout << fib(6) << endl;
	cout << fact(6) << endl;
}
