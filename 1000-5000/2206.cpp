#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e3 + 3;
const int INF = 1e9;
int mat[N][N];
// 벽을 부수고 새로 개척된 길로 가려할 때 이미 방문 처리된 노드에 갈 수 있는 방법을 만들기 위해서 visited를 3차원으로 관리
bool visited[2][N][N];
int dist[2][N][N];

int n, m;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct T {
    int r;
    int c;
    bool punch;
};

void bfs(T start) {
    queue<T> q;
    q.push({start.r, start.c, false});
    visited[0][start.r][start.c] = true;
    dist[0][start.r][start.c] = 0;

    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        bool punch = q.front().punch;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 1 || nr > n || nc < 1 || nc > m) continue;
            if(mat[nr][nc] == 0 && !visited[punch][nr][nc]) {
                dist[punch][nr][nc] = dist[punch][r][c] + 1;
                visited[punch][nr][nc] = true;
                q.push({nr, nc, punch});
            }
            else if(mat[nr][nc] == 1 && !punch && !visited[1][nr][nc]) {
                dist[1][nr][nc] = dist[0][r][c] + 1;
                visited[1][nr][nc] = true;
                q.push({nr, nc, true});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &mat[i][j]);
            dist[0][i][j] = INF;
            dist[1][i][j] = INF;
        }
    }
    bfs({1, 1, false});
    
    int ans = min(dist[0][n][m], dist[1][n][m]);
    if(ans == INF) cout << -1;
    else cout << ans + 1;
}
