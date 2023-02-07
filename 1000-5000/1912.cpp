#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 1e5+5;
int dp[N];

// int main() {
//     int n, a;
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         cin >> a;
//         dp[i] = max(dp[i-1] + a, a);
//     }
//     cout << endl << *max_element(dp+1, dp+n);;
// }

int main() {
    int n, a, maxval;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(i == 1) maxval = a;
        dp[i] = max(dp[i-1] + a, a);
        maxval = max(maxval, dp[i]);
    }
    cout << maxval;
}
