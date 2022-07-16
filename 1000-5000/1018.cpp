#include <iostream>
#include <algorithm>
using namespace std;
char board[50][50];

int Black(int x, int y) {
	int wrong_cnt = 0;
	for(int a=0; a<8; a++) {
		for(int b=0; b<8; b++) {
			if((a+x+b+y)%2 == 0) {
				if(board[a+x][b+y] == 'B') continue;
				else wrong_cnt++;
			}
			else {
				if(board[a+x][b+y] == 'W') continue;
				else wrong_cnt++;
			}
		}
	}
	return wrong_cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int N, M, tmp, ans=250;
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> board[i][j];
		}
	}
	for(int i=0; i<N-7; i++) { //총 몇세트를 탐색해야하는지 
		for(int j=0; j<M-7; j++) {
			tmp = Black(i, j);
			ans = min({ans, tmp, 64-tmp});
		}
	}
	cout << ans;
	return 0;
}
