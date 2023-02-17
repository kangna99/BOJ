// 1) deque 풀이(0-1 BFS)
#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

constexpr int N = 1e5+5;
int dist[N];
deque<int> dq;
int n, k, ans;

void bfs(int s) {
    dist[s] = 0;
    dq.push_back(s);
    while(!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        if(cur == k) break;
        if(cur*2 <= 100000 && dist[cur*2] < 0) dist[cur*2] = dist[cur], dq.push_front(cur*2);
        if(cur-1 >= 0 && dist[cur-1] < 0) dist[cur-1] = dist[cur] + 1, dq.push_back(cur-1);
        if(cur+1 <= 100000 && dist[cur+1] < 0) dist[cur+1] = dist[cur] + 1, dq.push_back(cur+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dist, -1, sizeof(dist));
    cin >> n >> k;
    bfs(n);
    cout << dist[k];
}


// // 2) queue 풀이(0-1 BFS)
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5;
// int dist[N + 5];

// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int n, k; scanf("%d %d", &n, &k);
//     queue<int> q;
//     q.push(n);
//     dist[n] = 1;
//     while (!q.empty()) {
//         int cur = q.front();
//         q.pop();
//         if (cur == k) {
//             printf("%d", dist[cur] - 1);
//             break;
//         }
//         for (int i = cur * 2; i <= N && !dist[i]; i *= 2) dist[i] = dist[cur], q.push(i);
//         if (cur - 1 >= 0 && !dist[cur - 1]) dist[cur - 1] = dist[cur] + 1, q.push(cur - 1);
//         if (cur + 1 <= N && !dist[cur + 1]) dist[cur + 1] = dist[cur] + 1, q.push(cur + 1);
//     }
// }
