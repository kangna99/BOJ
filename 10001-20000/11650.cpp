#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, y;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    for(int j = 0; j < n; j++) {
       cout << v[j].first << ' ' << v[j].second << '\n';
    }
}
