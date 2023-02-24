#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        string str; cin >> str;
        int ans = 0, cnt = 0;
        for(char c : str) {
            if(c == 'O') cnt++, ans += cnt;
            else cnt = 0;
        }
        cout << ans << '\n';
    }
}
