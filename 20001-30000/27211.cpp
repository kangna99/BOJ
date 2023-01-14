#include <iostream>
#define N 1001
using namespace std;

int n, m;
int arr[N][N];
bool visited[N][N];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    visited[r][c] = true;
    
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0) nr = n - 1;
        if(nc < 0) nc = m - 1;
        if(nr >= n) nr = 0;
        if(nc >= m) nc = 0;
        
        if(arr[nr][nc] == 0 && !visited[nr][nc]) {
            visited[nr][nc] = true;
            dfs(nr, nc);
        }
    }
 }

int main() {
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0 && !visited[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}