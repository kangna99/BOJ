#include <iostream>
#include <cstring>
using namespace std;

int k, n;
int dp[15][15];

void init() {
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 14; i++) {
        dp[0][i] = i;
    }
}

int solve() {
    cin >> k >> n;
    for(int floor = 1; floor <= k; floor++) {
        for(int room = 1; room <= n; room++) {
            dp[floor][room] = dp[floor-1][room] + dp[floor][room-1];
        }
    }
    return dp[k][n]; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++) {
        init();
        cout << solve() << '\n';
    }
}
