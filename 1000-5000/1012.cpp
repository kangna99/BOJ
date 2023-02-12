#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int mat[51][51];
bool visited[51][51];
int m, n, k, x, y;
vector<pair<int,int>> v;

void init() {
    memset(mat, 0, sizeof(mat));
    memset(visited, 0, sizeof(visited));
    v.clear();
}

void dfs(int r, int c) {
    visited[r][c] = true;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(mat[nr][nc] == 1 && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }
}

void input() {
    init();
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> y >> x;
        mat[x][y] = 1;
        v.push_back({x, y});
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc, row, col;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int ans = 0;
        input();
        for(auto const &front: v) {
            row = front.first;
            col = front.second;
            if(!visited[row][col]) {
                dfs(row, col);
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
