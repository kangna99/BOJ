#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 5e5+5;
int card[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> card[i];
    }
    sort(card, card + n);
    int m; cin >> m; 
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        cout << upper_bound(card, card+n, a) - lower_bound(card, card+n, a) << ' ';
    }
}
