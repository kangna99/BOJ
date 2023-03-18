#include <iostream>
using namespace std;

bool visited[1001];

int main() {
    int n, k; cin >> n >> k;
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            if(!visited[j]) cnt++, visited[j] = true;
            if(cnt == k) {
                cout << j;
                return 0;
            }
        }
    }
}
