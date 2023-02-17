#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a;
        cout << binary_search(v.begin(), v.end(), a) << '\n';
    }
}
