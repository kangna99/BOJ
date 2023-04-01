#include <iostream>
using namespace std;

int main() {
    int h, m; cin >> h >> m;
    int ret = h * 60 + m - 45;
    if(ret < 0) cout << 23 << ' ' << ret + 60;
    else cout << ret / 60 << ' ' << ret % 60;
}
