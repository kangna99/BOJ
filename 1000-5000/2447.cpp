#include <iostream>
using namespace std;

void dc(int i, int j, int n) {
    if((i/n) % 3 == 1 && (j/n) % 3 == 1) cout << ' ';
    else if (n/3 == 0) cout << '*';
    else dc(i, j, n/3);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) dc(i, j, n);
        cout << '\n';
    }
}
