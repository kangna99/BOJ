#include <iostream>
using namespace std;

constexpr int N = 16;
int chess[N]; // 체스판 행에다가 열의 위치를 저장하기 위한 배열
int n, ans;

bool checkQueen(int r) {
    // 같은 행에는 넣을 수 없으니 같은 열인지, 대각선상인지만 확인하면 됨.
    for(int i = 0; i < r; i++) { // 현재 행까지 모두 검사
        if(chess[r] == chess[i] || r - i == abs((chess[r] - chess[i]))) // 같은 열이거나 대각선상이라면 return false
            return false;
    }
    return true;
}

// n행 돌면서 어느 열에 넣을건지를 정하면 됨. 한 줄에 하나씩 넣어야 하니까.
// 가로, 세로, 대각선 위치를 제외시키면 됨.
void putQueen(int r) {
    if(r == n) {
        ans++;
        return;
    }

    for(int c = 0; c < n; c++) {
        chess[r] = c; // 퀸을 넣어보고
        if(checkQueen(r)) // promising 하다면
            putQueen(r + 1); // 다음 행 퀸 자리 정함
    }
}

int main() {
    cin >> n;
    putQueen(0);
    cout << ans;
}
