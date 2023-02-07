#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 1e5+5;
int dpLeft[N], dpRight[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, a;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a == 1) {
            dpLeft[i] = max(dpLeft[i-1] + 1, 1);
            dpRight[i] = dpRight[i-1] - 1;
        }
        if(a == 2) {
            dpLeft[i] = dpLeft[i-1] - 1;
            dpRight[i] = max(dpRight[i-1] + 1, 1);
        }
    }
    cout << max(*max_element(dpLeft+1, dpLeft+n+1), *max_element(dpRight+1, dpRight+n+1));
}
