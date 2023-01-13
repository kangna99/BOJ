#include <iostream>
using namespace std;

int n, ans;
constexpr int N = 1e6+6;
int dp[N];

// bottom-up 반복문
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i-1];
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    cout << dp[n];
}
