#include <iostream>
#define MAX 2000
using namespace std;

// int dp[5001]; // dp[a] = b : 무게가 a일 때 봉지 수 b

int main() {
    // 1. 그리디
    int n, ans = 0;
    cin >> n;
    while(n > 0) {
        if(n % 5 == 0) {
            ans += n / 5;
            break;
        }
        n -= 3; ans++;
        if(n < 0) {
            ans = -1;
            break;
        }
    }
    cout << ans;

    // // 2. 동적계획법
    // int n;
    // cin >> n;
    // fill(dp, dp+5001, MAX);
    // dp[3] = dp[5] = 1;
    // for(int i = 6; i <= n; i++) {
    //     dp[i] = min(dp[i-3], dp[i-5]) + 1;
    // }
    // if(dp[n] >= MAX) cout << -1;
    // else cout << dp[n];
}
