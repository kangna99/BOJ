#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    for(int i = 2; i >= 0; i--) {
        cout << stoi(a) * (b[i] - '0') << endl;
    }
    cout << stoi(a) * stoi(b);
}
