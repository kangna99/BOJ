#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

constexpr int N = 1e5+5;
int dist[N];
queue<int> q;
int n, k, ans;

void bfs(int s) {
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == k) break;
        for(int nxt : {cur-1, cur+1, cur*2}) {
            if(nxt < 0 || nxt > 100000 || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    // while(!q.empty()) {
    //     int cur = q.front(); q.pop();
    //     if(cur == k) break;
    //     if(cur-1 > 0 && dist[cur-1] < 0) {
    //         dist[cur-1] = dist[cur] + 1;
    //         q.push(cur-1);
    //     }
    //     if(cur+1 <= 100000 && dist[cur+1] < 0) {
    //         dist[cur+1] = dist[cur] + 1;
    //         q.push(cur+1);
    //     }
    //     if(cur*2 <= 100000 && dist[cur*2] < 0) {
    //         dist[cur*2] = dist[cur] + 1;
    //         q.push(cur*2);
    //     }
    // }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dist, -1, sizeof(dist));
    cin >> n >> k;
    bfs(n);
    cout << dist[k];
}