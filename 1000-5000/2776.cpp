#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    vector<int> list;
    int n, m, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        list.push_back(a);
    }
    sort(list.begin(), list.end());
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a;
        cout << (binary_search(list.begin(), list.end(), a)) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        solve();
    }
}
