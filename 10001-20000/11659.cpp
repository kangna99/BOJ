#include <iostream>
using namespace std;

constexpr int N = 1e5+5;
int dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b, num;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        dp[i] = dp[i-1] + num;
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << '\n';
    }
}
