#include <iostream>
using namespace std;

constexpr int MOD = 1e9;
int sum;
int dp[101][10];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if (j == 0) dp[i][0] = dp[i-1][j+1];
            else if (j == 9) dp[i][9] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }
    for(int i = 0; i <= 9; i++) {
        sum = (sum + dp[n][i]) % MOD;
    }
    cout << sum;
}
