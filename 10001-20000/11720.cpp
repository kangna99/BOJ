#include <iostream>
using namespace std;

int ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string str; cin >> str;
    for(char &c : str) {
        c -= '0';
        ans += c;
    }
    cout << ans;
}
