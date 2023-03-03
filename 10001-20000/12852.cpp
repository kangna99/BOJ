#include <iostream>
#include <algorithm>

using namespace std;
constexpr int N = 1e6+6;
int dp[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
   
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        ans[i] = i-1;
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            ans[i] = i/3;
        }
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            ans[i] = i/2;
        }
    }
    cout << dp[n] << endl;
    while(n != 0) cout << n << ' ', n = ans[n];   
}
