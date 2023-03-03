#include <iostream>
#define ll long long
using namespace std;

ll dc(int a, int b, int c) {
    if(b == 0) return 1;
    if(b == 1) return a % c;
    if(b % 2 == 0) {
        ll ret = dc(a, b / 2, c);
        return ret * ret % c;
    }
    else {
        ll ret = dc(a, (b-1)/2, c);
        return ret * ret % c * a % c;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    cout << dc(a, b, c);
}
