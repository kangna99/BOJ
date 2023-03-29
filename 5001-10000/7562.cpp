#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int adj[301][301];
bool visited[301][301];
int sz, cur_r, cur_c, nxt_r, nxt_c;
queue<pair<pair<int, int>, int>> q;

void init() {
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    while(!q.empty()) q.pop();
}

int bfs(int r, int c) {
    int cnt = 0;
    q.push({{r, c}, cnt});
    visited[r][c] = true;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        auto [r, c] = cur.first;
        int cnt = cur.second;
        adj[r][c] = cnt;
        if(r == nxt_r && c == nxt_c) break;
        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= sz || nc < 0 || nc >= sz) continue;
            if(!visited[nr][nc]) {
                q.push({{nr, nc}, cnt+1});
                visited[nr][nc] = true;
            }
        }
    }
    return adj[nxt_r][nxt_c];
}

void solve() {
    cin >> sz;
    cin >> cur_r >> cur_c;
    cin >> nxt_r >> nxt_c;
    init();
    cout << bfs(cur_r, cur_c) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        solve();
    }
}
