#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) cnt++;
        if(cnt == k) {
            ans = i;
            break;
        }
    }
    if(cnt < k) cout << 0;
    else cout << ans;
}
