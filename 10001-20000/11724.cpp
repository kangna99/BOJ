#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 1e3+3;
int n, m, u, v, ans;
int visited[N];
vector<int> graph[N];

void dfs(int s) {
    visited[s] = true;
    for(int nxt: graph[s]) {
        if(!visited[nxt]) dfs(nxt);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans;
}