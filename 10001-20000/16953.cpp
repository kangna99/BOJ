#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll a, b;
    int ans = 1;
    cin >> a >> b;
    queue<pair<ll, int>> q;
    q.push({a, ans});
    while(!q.empty()) {
        auto [na, ans] = q.front(); q.pop();
        if(na == b) {
            cout << ans; 
            return 0;
        }
        for(ll nxt : {na*2, na*10+1}) {
            if(nxt <= b) q.push({nxt, ans+1});
        }
    }
    cout << -1;
}
