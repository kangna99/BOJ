#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

// 일찍 끝나고 -> 일찍 시작하는 것 우선으로 정렬
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, start, end;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), compare);
    int endtime = v[0].second;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(endtime <= v[i].first) {
            ans++;
            endtime = v[i].second;
        }
    }
    cout << ans << '\n';
}