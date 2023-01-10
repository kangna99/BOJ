#include <iostream>
#include <algorithm>
#define N 21
using namespace std;

int r, c, ans;
bool visited[26]; // 알파벳 방문 배열
string arr[N];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> arr[i];
    }
}

void solve(int row, int col, int cnt) {
    for(int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
        else if(!visited[arr[nr][nc] - 'A']) {
            visited[arr[nr][nc] - 'A'] = true;
            solve(nr, nc, cnt+1);
            visited[arr[nr][nc] - 'A'] = false;
        }
    }
    ans = max(ans, cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    input();
    visited[arr[0][0] - 'A'] = true;
    solve(0, 0, 1);
    cout << ans;
}
