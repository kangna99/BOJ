#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define SPCAE 0
#define HOUSE 1
#define CHICKEN 2
using namespace std;

constexpr int INF = 1e9;
int n, m, ans = INF;
int adj[51][51];
bool visited[13];
vector<pair<int, int>> housev;
vector<pair<int, int>> chickenv;
vector<pair<int, int>> selected;

int calcDist(pair<int, int> h, pair<int, int> s) {
    return abs(h.first - s.first) + abs(h.second - s.second);
}

void dfs() {
    int result = 0;
    for(int i = 0; i < housev.size(); i++) {
        int min_d = INF;
        for(int j = 0; j < selected.size(); j++) {
            min_d = min(min_d, calcDist(housev[i], selected[j]));
        }
        result += min_d;
    }
    ans = min(ans, result);
}

void select(int cnt, int start) {
    if(cnt == m) return dfs();
    for(int i = start; i < chickenv.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            selected.push_back(chickenv[i]);
            select(cnt+1, i+1);
            visited[i] = false;
            selected.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == HOUSE) housev.push_back({i, j});
            if(adj[i][j] == CHICKEN) chickenv.push_back({i, j});
        }
    }
    select(0, 0);
    cout << ans << '\n';
}
