#include <iostream>
using namespace std;

char star[3100][6200];

void recursion(int row, int col, int len) {
	if(len == 3) {
		star[row][col] = '*';
		star[row + 1][col - 1] = '*';
		star[row + 1][col + 1] = '*';
		for(int i = 0; i < 5; i++) {
			star[row + 2][col - 2 + i] = '*';
		}
		return;
	}
	recursion(row, col, len/2);
	recursion(row+len/2, col-len/2, len/2);
	recursion(row+len/2, col+len/2, len/2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2*n-1; j++) {
			star[i][j] = ' ';
		}
	}
	recursion(0, n-1, n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2*n-1; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}
