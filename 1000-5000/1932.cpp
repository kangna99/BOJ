#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
constexpr int N = 5e2+2;
vector<int> triangle[N];
int dp[N][N];

int dpf(int level, int idx) {
    int &ret = dp[level][idx];
    if(~ret) return dp[level][idx];
    if(level == 1) return ret;
    if(idx == 0) dp[level][idx] = dpf(level-1, idx) + triangle[level][idx];
    else if(idx == level-1) dp[level][idx] = dpf(level-1, idx-1) + triangle[level][idx];    
    else dp[level][idx] = max(dpf(level-1, idx-1), dpf(level-1, idx)) + triangle[level][idx];

    return ret;     
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int m; cin >> m;
            triangle[i].push_back(m);
        } 
    }
    dp[1][0] = triangle[1][0];
    for(int i = 0; i < n; i++) {
        dpf(n, i);
    }
    cout << *max_element(&dp[n][0], &dp[n][n]);
}
