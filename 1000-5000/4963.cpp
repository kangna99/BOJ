#include <iostream>
#include <vector>
#include <cstring>
#define SEA 0
#define LAND 1
using namespace std;

vector<pair<int, int>> v;
int adj[50][50];
bool visited[50][50];
int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int row, col, cnt;

void init() {
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    v.clear();
    cnt = 0;
}

void solve(int r, int c) {
    visited[r][c] = true;
    for(int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
        if(adj[nr][nc] == SEA) continue;
        if(!visited[nr][nc] && adj[nr][nc] == LAND) solve(nr, nc);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(cin >> col >> row) {
        if(row == 0 && col == 0) break;
        init();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin >> adj[i][j];
                if(adj[i][j] == LAND) v.push_back({i, j});
            }
        }
        for(auto [r, c] : v) {
            if(!visited[r][c]) {
                cnt++;
                solve(r, c);
            }
        }
        cout << cnt << '\n';
    }
}
