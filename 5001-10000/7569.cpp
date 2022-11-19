#include <bits/stdc++.h>
using namespace std;

const int N = 1e+2;
int mat[N][N][N];
queue<pair<int, pair<int, int>>> q;
int m, n, h;

// 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dr[6] = {0, 0, 0, 0, -1, 1};
int dc[6] = {0, 0, -1, 1, 0, 0};
int dt[6] = {1, -1, 0, 0, 0, 0};

void bfs() {
    while(!q.empty()) {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int t = q.front().first;
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nt = t + dt[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || nt < 0 || nt >= h) continue;
            if(mat[nt][nr][nc] == -1) continue;
            else if(mat[nt][nr][nc]== 0) {
                mat[nt][nr][nc] = mat[t][r][c] + 1;
                q.push({nt, {nr, nc}});
            }
        }
    }
}

int checkRipen() {
    int result = -1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n ; j++) {
            for (int k = 0; k < m; k++) {
                if(mat[i][j][k] == 0) return -1;
                result = max(result, mat[i][j][k]);
            }
        }
    }
    return result - 1;
}

int main() {
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n ; j++) {
            for (int k = 0; k < m; k++) {
                cin >> mat[i][j][k];
                if(mat[i][j][k] == 1) {
                    q.push({i, {j, k}});
                }
            }
        }
    }
    bfs();
    cout << checkRipen();
}
