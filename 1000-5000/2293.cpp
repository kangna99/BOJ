#include <iostream>
using namespace std;

constexpr int N = 1e4 + 4;
int dp[N]; // dp[a] = b, a원을 만드는 경우의 수 b가지
int n, k;
int coin[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = coin[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    cout << dp[k] << '\n';
}
