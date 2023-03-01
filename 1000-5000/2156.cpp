#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 1e4+4;
int arr[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i = 3; i <= n; i++) {
        dp[i] = max({dp[i-1], dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]});
    }
    cout << dp[n];
}
