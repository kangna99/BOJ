#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+2;
int mat[N][N];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int n, m;

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nr > n || nc < 1 || nc > m) continue;
            if(mat[nr][nc] == 0) continue;
            else if(mat[nr][nc] == 1) {
                q.push({nr, nc});
                mat[nr][nc] = mat[r][c] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &mat[i][j]);
        }
    } 
    bfs({1, 1});
    cout << mat[n][m];
}
