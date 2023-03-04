#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr int N = 1e5+5;
int dp[2][N];

int n;

void solve() {
    for(int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + dp[0][i];
		dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + dp[1][i];
    }
    cout << max(dp[0][n], dp[1][n]) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> dp[i][j];
            }
        }
        solve();
    }
}
