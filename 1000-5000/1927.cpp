#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == 0) {
            if(!pq.size()) cout << 0 << '\n';
            else cout << pq.top() << '\n', pq.pop();
        }
        else pq.push(a);
    }
}
