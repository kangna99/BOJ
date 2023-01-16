#include <iostream>
using namespace std;

int n, k;
int weight[101];
int value[101];
int dp[101][100001]; // dp[i][j] = c : i번째 물건, 현재 남은 배낭의 무게 j, 그때의 가치 c

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= k; j++) {// 합이 k보다 작아야함
            // i번째 물건을 선택하는 경우와 선택하지 않는 경우 중 가치가 큰 값을 고름
            dp[i][j] = dp[i-1][j];
            if(j >= weight[i]) dp[i][j] = max(dp[i-1][j-weight[i]] + value[i], dp[i-1][j]);
        }
    }
    cout << dp[n][k];
}
