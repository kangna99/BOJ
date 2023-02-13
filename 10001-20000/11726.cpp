#include <iostream>
using namespace std;

int dp[1001] = {0, 1, 2, 3};

// 1 또는 2로 n만드는 경우의 수
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 4; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n];
}
