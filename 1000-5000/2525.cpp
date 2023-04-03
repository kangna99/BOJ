#include <iostream>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ret = a * 60 + b + c;
    if(ret >= 24 * 60) ret -= 24 * 60;
    cout << ret / 60 << ' ' << ret % 60;
}
