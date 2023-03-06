#include <iostream>
using namespace std;

void solve() {
    long long ans = 1;
    int n, m, r = 1;
    cin >> n >> m;
    for(int i = m; i > m - n; i--) {
        ans *= i;
        ans /= r++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        solve();
    }
}
