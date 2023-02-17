#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

constexpr int N = 2e5+5;
constexpr int INF = 1e9;
int vertex, edge, k, u, v, w;
int dist[N];
vector<pair<int, int>> adj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최단 거리를 가진 순으로 정렬

//1. 우선순위 큐에 (0, 시작점)을 추가
//2. 우선순위 큐에서 거리가 가장 작은 원소를 선택, 해당 거리가 최단 거리 테이블에 있는 값과 다를 경우 넘어감
//3. 원소가 가리키는 정점을 v라고 할 때, v와 이웃한 정점들에 대해 최단 거리 테이블 값보다 v를 거쳐가는 것이 더 작은 값을 가질 경우 최단 거리 테이블의 값을 갱신하고 우선순위 큐에 (거리, 이웃한 정점의 번호)를 추가
//4. 우선순위 큐가 빌 때까지 2, 3번 과정을 반복

void dijkstra(int s) {
    fill(dist, dist+vertex+1, INF);
    dist[s] = 0;
    pq.push({0, s}); // 시작노드에서 시작 노드로 가는 경로와 비용을 push
    while(!pq.empty()) {
        auto [cur_d, cur] = pq.top(); pq.pop();
        if(dist[cur] < cur_d) continue;
        for(int i = 0; i < adj[cur].size(); i++) {
            auto [nxt_d, nxt] = adj[cur][i];
            if(dist[nxt] > dist[cur] + nxt_d) { // 테이블 갱신
                dist[nxt] = dist[cur] + nxt_d;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> vertex >> edge >> k;
    for(int i = 0; i < edge; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); // 비용과 도착 노드 저장
    }
    dijkstra(k);
    for(int i = 1; i <= vertex; i++) {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
