#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; cin >> a >> b;
    printf("%d\n%d\n%d\n%d\n%d", a+b, a-b, a*b, a/b, a%b);
}
