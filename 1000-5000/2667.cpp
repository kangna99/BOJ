#include <bits/stdc++.h>
using namespace std;

const int N = 26;
string mat[N];
bool visited[N][N];
vector<int> result;
int n, cnt;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int r, int c) {
    visited[r][c] = true;
    
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(mat[nr][nc] == '1' && !visited[nr][nc]) {
            cnt++;
            dfs(nr, nc);
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j]=='1' && !visited[i][j]) {
                cnt = 1;
                result.push_back(dfs(i, j));
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}
