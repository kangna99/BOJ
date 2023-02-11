#include <iostream>
#include <cstring>
using namespace std;

int dp[11];

// 1. bottom-up 반복문
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc, n, ans = 0;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> n;
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << '\n';
    }        
}


// // 2. top-down 재귀
// int dpf(int i) {
//     if(i == 0) return 1;
//     if(i == 1) return 1;
//     if(i == 2) return 2;
//     if(dp[i] != -1) return dp[i];
//     return dp[i] = dpf(i-1) + dpf(i-2) + dpf(i-3);
// }

// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int tc, n;
//     cin >> tc;
//     for(int t = 1; t <= tc; t++) {
//         memset(dp, -1, sizeof(dp));
//         cin >> n;
//         cout << dpf(n) <<'\n';
//     }
// }