#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, a, ans;
int dp[1001]; // dp[a] = b a위치까지의 최장길이 b

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
