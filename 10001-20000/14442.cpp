#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

constexpr int N = 1e3 + 3;
int arr[N][N];
bool visited[11][N][N];
int dist[11][N][N];

struct T {
    int punch;
    int r;
    int c;
};
queue<T> q;
int n, m, k;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs() {
    while(!q.empty()) {
        int punch = q.front().punch;
        int r = q.front().r;
        int c = q.front().c;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if(nr < 1 || nr > n || nc < 1 || nc > m) continue;
            if(arr[nr][nc] == 0 && !visited[punch][nr][nc]) {
                dist[punch][nr][nc] = dist[punch][r][c] + 1;
                visited[punch][nr][nc] = true;
                q.push({punch, nr, nc});
            }
            else if(arr[nr][nc] == 1 && punch > 0 && !visited[punch-1][nr][nc]) {
                dist[punch-1][nr][nc] = dist[punch][r][c] + 1;
                visited[punch-1][nr][nc] = true;
                q.push({punch-1, nr, nc});
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
            for(int p = 0; p <= k; p++) {
                dist[p][i][j] = INF;
            }
        }
    }
    q.push({k, 1, 1});
    visited[k][1][1] = true;
    dist[k][1][1] = 0;
    bfs();
    int result = INF;
    for(int i = 0; i <= k; i ++) {
        result = min(dist[i][n][m], result);
    }
    if(result == INF) cout << -1;
    else cout << result + 1;
}
