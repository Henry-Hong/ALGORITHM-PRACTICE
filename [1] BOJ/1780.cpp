#include <iostream>
using namespace std;

int n, neg=0, zero=0, pos=0;
char arr[2187][2187];


void divideAndConquer(int x, int y, int w) {

	char flag = arr[y][x];
	for (int i = y; i < y + w; i++) {
		for (int j = x; j < x + w; j++) {
			if (flag != arr[i][j]) {

				divideAndConquer(x, y, w / 3);
				divideAndConquer(x + w/3, y, w / 3);
				divideAndConquer(x + w/3 + w/3, y, w / 3);

				divideAndConquer(x, y + w/3, w / 3);
				divideAndConquer(x + w/3, y + w/3, w / 3);
				divideAndConquer(x + w/3 + w/3, y + w/3, w / 3);

				divideAndConquer(x, y + w/3 + w/3, w / 3);
				divideAndConquer(x + w/3, y + w/3 + w/3, w / 3);
				divideAndConquer(x + w/3 + w/3, y + w/3 + w/3, w / 3);

				return;
			}
		}
	}
	if (flag == '0')
		neg++;
	else if (flag == '1')
		zero++;
	else
		pos++;
	return;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			arr[i][j] = t + 1 + '0'; // -1(0), 0(1), 1(2)
		}
	}

	divideAndConquer(0, 0, n);

	cout << neg << "\n" << zero << "\n" << pos;

	return 0;
}