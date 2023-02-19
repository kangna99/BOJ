#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
#define SPACE 0
#define WALL 1
#define VIRUS 2
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int n, m, cnt, ans;
int adj[9][9]; int tmp[9][9];
bool visited[9][9];
queue<pair<int, int>> virus;

void checkSpace() {
    int maxval = 0; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(tmp[i][j] == 0) maxval++;
        }
    }
    ans = max(maxval, ans);
}

void bfs() {
    memset(visited, 0, sizeof(visited));
    copy(&adj[0][0], &adj[8][9], &tmp[0][0]);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(tmp[i][j] == VIRUS) {
                virus.push({i, j});
                visited[i][j] = true;
                while(!virus.empty()) {
                    auto [row, col] = virus.front(); virus.pop();
                    for(int i = 0; i < 4; i++) {
                        int nr = dr[i] + row;
                        int nc = dc[i] + col;
                        if(nr < 1 || nr > n || nc < 1 || nc > m) continue;
                        if(tmp[nr][nc] == SPACE && !visited[nr][nc]) {
                            tmp[nr][nc] = 2;
                            virus.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                }
            }
        }
    }
    checkSpace();
}

void setWalls() {
    if(cnt == 3) return bfs();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(adj[i][j] == SPACE) {
                cnt++;
                adj[i][j] = WALL;
                setWalls();
                cnt--;
                adj[i][j] = SPACE;
            }
        }
    }
}

void solve() {
    setWalls();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> adj[i][j];
        }
    }
    solve();
    cout << ans;
}
