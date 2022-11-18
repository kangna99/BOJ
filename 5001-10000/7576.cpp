#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
int matrix[N][N];
queue<pair<int, int>> q;

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, -0, -1, 1};

int m, n;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            else if(matrix[nx][ny] == -1) continue;
            else if(matrix[nx][ny] == 0) {
                matrix[nx][ny] = matrix[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int checkRipen() {
    int max = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) 
                return -1;
            else if(matrix[i][j] > max)
                max = matrix[i][j];
        }
    }
    return max - 1;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    bfs();
    cout << checkRipen();
}
