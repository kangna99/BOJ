#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    priority_queue<int, vector<int>> pq;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == 0) {
            if(!pq.empty()) cout << pq.top() << '\n', pq.pop();
            else cout << 0 << '\n';
        }
        else pq.push(a); 
    }
}
