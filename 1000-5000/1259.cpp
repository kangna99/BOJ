#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s, tmp;
    while(true) {
        cin >> s;
        if(s == "0") break;
        tmp = s;
        reverse(tmp.begin(), tmp.end());
        if(s == tmp) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}
