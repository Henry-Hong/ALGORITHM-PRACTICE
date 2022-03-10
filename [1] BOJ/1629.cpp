#include <iostream>
#define longint long long 
using namespace std;

longint divide(longint x, longint n, longint c) {

	if (n == 1 || x == 1) return x % c;

	longint t = divide(x, n / 2, c) % c;

	if (n % 2 == 0) return (t * t) % c;
	else return ((t * t % c) * x) % c;
}

int main() {

	longint A, B, C, ans=0;

	cin >> A >> B >> C;

	ans = divide(A, B, C);

	cout << ans;

	return 0;
}