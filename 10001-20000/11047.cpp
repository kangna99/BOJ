#include <iostream>
using namespace std;

int n, k, ans;
int coin[10];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for(int i = n-1; i >= 0; i--) {
        ans += k / coin[i];
        k %= coin[i];
    }
    cout << ans;
}