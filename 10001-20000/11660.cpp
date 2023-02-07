#include <iostream>
using namespace std;

constexpr int N = 1025;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, num, x1, y1, x2, y2;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> num;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]<< '\n';
    }
}
