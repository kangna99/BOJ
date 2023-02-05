#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N = 100001;
int n, m, a, b;
int dp[20][N]; // N의 i번째 부모노드
int depth[N];
bool visited[N];
vector<int> tree[N];
queue<int> q;

int LCA(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b); // 항상 b의 depth가 더 큼
    for(int i = 19; i >= 0; i--) {
        if(depth[b] - depth[a] >= (1 << i)) b = dp[i][b];
    }
    if(a == b) return a;
    for(int i = 19; i >= 0; i--) {
        if (dp[i][a] != dp[i][b]) {
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}

void findParent() {
    for(int i = 1; i < 20; i++) { // 1부터 19번째 조상까지 계산
        for(int j = 1; j <= n; j++) { // n노드까지 조사
            dp[i][j] = dp[i-1][dp[i-1][j]]; // j의 2^i번째 조상 == j의 2^(i-1)번째 조상의 2^(i-1)번째 조상
            // printf("%d의 %d번째 조상 = %d\n", j, (1<<i), dp[i-1][dp[i-1][j]]);
        }
    }
}

void depthCalc() {
    q.push(1); 
    visited[1] = true;
    depth[1] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < tree[cur].size(); i++) {
            int nxt = tree[cur][i];
            if(!visited[nxt]) {
                q.push(nxt);
                visited[nxt] = true;
                depth[nxt] = depth[cur] + 1;
                dp[0][nxt] = cur;
            }
        }        
    }
}

void makeTree() {
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    depthCalc();
    findParent();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    makeTree();
    cin >> m;
    while(m--) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}