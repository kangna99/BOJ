#include <iostream>
using namespace std;

int dp[1001] = {0, 1, 3, 5};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 4; i <= n; i++) {
        dp[i] = (dp[i-2]*2 + dp[i-1]) % 10007;
    }
    cout << dp[n];
}