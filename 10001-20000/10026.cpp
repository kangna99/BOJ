#include <iostream>
#include <cstring>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char adj[100][100];
int visited[100][100];
int n, cnt, disabledCnt;

void dfs(int r, int c) {
    char color = adj[r][c];
    visited[r][c] = true;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(!visited[nr][nc] && color == adj[nr][nc]) dfs(nr, nc);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> adj[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) dfs(i, j), cnt++;
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 'R') adj[i][j] = 'G';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) dfs(i, j), disabledCnt++;
        }
    }
    cout << cnt << " " << disabledCnt;
}
