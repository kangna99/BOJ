#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
int n, m, v, a, b;
vector<int> matrix[N];
bool visited[N];

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";
    for(int nxt : matrix[cur]) {
        if(!visited[nxt]) {
            dfs(nxt);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for(int nxt : matrix[cur]) {
            if(!visited[nxt]) {
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        sort(matrix[i].begin(), matrix[i].end());
    }
    
    dfs(v);
    for(int i = 0; i < N; i++) {
        visited[i] = false;
    }
    cout << "\n";
    bfs(v);
}
