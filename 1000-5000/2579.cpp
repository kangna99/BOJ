#include <iostream>
using namespace std;

int arr[301];
int dp[301];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    
    for(int i = 4; i <= n; i++) {
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]); // 한칸 뛰어넘었을 때가 더 큰지, 연속해서 두 개 밟은 때가 더 큰지    
    }
    cout << dp[n];
}
