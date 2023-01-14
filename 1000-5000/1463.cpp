#include <iostream>
#include <cstring>
using namespace std;

int n, ans;
constexpr int N = 1e6+6;
int dp[N];

// // #1 bottom-up 반복문
// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int n;
//     cin >> n;
//     dp[1] = 0;
//     for(int i = 2; i <= n; i++) {
//         dp[i] = 1 + dp[i-1];
//         if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
//         if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
//     }
//     cout << dp[n];
// }

// #2 top-down 재귀
int func(int n) {
    if(n == 1)  return 0;
    if(dp[n] != -1) return dp[n]; // memoization으로 인한 값 리턴
    
    dp[n] = func(n - 1) + 1;
    if(n % 2 == 0) dp[n] = min(dp[n], func(n / 2) + 1);
    if(n % 3 == 0) dp[n] = min(dp[n], func(n / 3) + 1);

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << func(n);
}
