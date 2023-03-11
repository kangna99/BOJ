#include <iostream>
using namespace std;

int quad[65][65];

void dc(int r, int c, int n) {
    bool flag = true;
    int base = quad[r][c];
    if(n == 1) {
        cout << quad[r][c];
        return;
    }
    for(int i = r; i < r+n; i++) {
        for(int j = c; j < c+n; j++) {
            if(quad[i][j] != base) {
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << base;
    else {
        cout << '(';
        dc(r, c, n/2);
        dc(r, c+n/2, n/2);
        dc(r+n/2, c, n/2);
        dc(r+n/2, c+n/2, n/2);
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(int j = 0; j < n; j++) {
            quad[i][j] = str[j] - '0';
        }
    }
    dc(0, 0, n);  
}
