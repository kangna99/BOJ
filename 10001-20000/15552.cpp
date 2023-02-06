#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc, a, b;
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}