#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
bool visited[101];
int ans;

void dfs(int s) {
    visited[s] = true;
    for(int nxt : v[s]) {
        if(!visited[nxt]) dfs(nxt);
    }
    ans++;
}

int main() {
    int n, e, a, b;
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << ans - 1;
}
