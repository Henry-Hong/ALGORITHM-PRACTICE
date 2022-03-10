#include <iostream>
using namespace std;

int n, idx=0;
char arr[64][64] = { 0 };
char str[10000] = { 0 };

void divideAndConquer(int x, int y, int w) {

	char flag = arr[y][x];
	for (int i = y; i < y + w; i++) {
		for (int j = x; j < x + w; j++) {
			if (flag != arr[i][j]) {
				str[idx++] = '(';
				divideAndConquer(x, y, w / 2);
				divideAndConquer(x + w / 2, y, w / 2);
				divideAndConquer(x, y + w / 2, w / 2);
				divideAndConquer(x + w / 2, y + w / 2, w / 2);
				str[idx++] = ')';
				return;
			}
		}
	}

	str[idx++] = flag;
	return;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	divideAndConquer(0, 0, n);

	for (int i = 0; i < idx; i++) {
		cout << str[i];
	}

	return 0;
}