#include <iostream>
#include <cstring>
using namespace std;

int dp[41];
int zero, one;

void init() {
    zero = one = 0;
    memset(dp, -1, sizeof(dp));
}

int dpf(int n) {
    if(n == 0 || n == 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = dpf(n-1) + dpf(n-2);
}


int main() {
    int tc, n;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cin >> n;
        init();
        if(n == 0) cout << "1 0\n";
        else cout << dpf(n-1) << ' ' << dpf(n) << '\n';
    }
}
