#include <iostream>
#include <cstring>
using namespace std;

long long dp[91];

// // #1 반복문으로 구현
// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int n;
//     cin >> n;
//     dp[0] = 0; dp[1] = 1;
//     for(int i = 2; i <= n; i++) {
//         dp[i] = dp[i-2] + dp[i-1];
//     }
//     cout << dp[n];
// }

// #2 재귀로 구현
long long recursive(int n) {
    if(n == 0 || n == 1) return n;
    if(dp[n] == -1) dp[n] = recursive(n-2) + recursive(n-1);
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << recursive(n);
}
