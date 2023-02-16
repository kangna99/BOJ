#include <iostream>
using namespace std;

int count[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        count[a]++;
    }
    for(int i = 1; i <= 10000; i++) {
        for(int j = 0; j < count[i]; j++) {
            cout << i << '\n';
        }
    }
}
