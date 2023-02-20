#include <iostream>
#include <cstring>
using namespace std;

int p;
string str;

void solve() {
  string ans = "";
  for(char c : str) {
    for(int i = 0; i < p; i++) {
      ans += c;
    }
  }
  cout << ans << '\n';
}

int main() {
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> p >> str;
        solve();
    }
}