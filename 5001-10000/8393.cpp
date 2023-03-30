#include <iostream>
using namespace std;

int sum;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
}
