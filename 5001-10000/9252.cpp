#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string str1, str2, ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    str1 = "#" + str1;
    str2 = "#" + str2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';

	while (dp[n][m]) {
		if (dp[n][m] == dp[n-1][m]) n--;
		else if (dp[n][m] == dp[n][m - 1]) m--;
		else {
			ans += str1[n];
			n--, m--;
		}
	}
	if (ans.size() > 0) {
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
}
