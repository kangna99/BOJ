#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

constexpr int N = 1e5+5;
int n, k, ans;
int dist[N];
int cnt[N];
queue<int> q;

void bfs(int s) {
    dist[s] = 0;
    cnt[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : {cur-1, cur+1, cur*2}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) {
                if(dist[nxt] == dist[cur]+1) cnt[nxt] += cnt[cur];
            }
            else {
                dist[nxt] = dist[cur] + 1;
                cnt[nxt] = cnt[cur];
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dist, -1, sizeof(dist));
    cin >> n >> k;
    bfs(n);
    cout << dist[k] << endl << cnt[k];
}
