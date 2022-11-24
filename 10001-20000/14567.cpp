#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N = 1e3+3;
constexpr int M = 5e5+5;
vector<int> mat[M];
queue<int> q;
int inDeg[N];
int dist[N];
int n, m, a, b;

void bfs() {
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt: mat[cur]) {
            if(!--inDeg[nxt]) {
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a].push_back(b);
        inDeg[b]++;
    }
    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) {
            q.push(i);
        }
    }
    bfs();
    for(int i = 1; i <= n; i++) {
        cout << dist[i] + 1 << " ";
    }
}
