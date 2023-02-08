#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 1e5+5;
vector<int> tree[N];
int parent[N];
bool visited[N];

void dfs(int cur) {
    visited[cur] = true;
    for(int nxt : tree[cur]) {
        if(!visited[nxt]) {
            parent[nxt] = cur;
            dfs(nxt);
        }
    } 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    for(int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
}
