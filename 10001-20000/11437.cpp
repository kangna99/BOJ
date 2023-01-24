#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N = 5e4+4;
int n, m, a, b;
bool visited[N];
int parent[N];
int depth[N];
vector<int> tree[N];
queue<int> q;

int LCA(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b); // depth[b]가 항상 depth[a]보다 큼 
    while(depth[a] != depth[b]) b = parent[b]; // 두 노드의 깊이가 같아질 때까지 깊이가 더 깊은 노드를 올림
    while(a != b) { // 공통 노드를 찾을 때까지 위로 올라감
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void makeTree() {
    // 루트 노드부터 방문하여 트리를 만들면서 각 노드의 부모 노드와 깊이를 저장
    visited[1] = true;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < tree[cur].size(); i++) {
            int nxt = tree[cur][i];
            if(!visited[nxt]) {
                depth[nxt] = depth[cur] + 1;
                parent[nxt] = cur;
                visited[nxt] = true;
                q.push(nxt);
            }
        }    
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    makeTree();

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}
