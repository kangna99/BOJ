#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, ss, t, tt;
int len_s, len_t, lcmval;

int main() {
    cin >> s >> t;
    len_s = s.size();
    len_t = t.size();
    lcmval = len_s * len_t / __gcd(len_s, len_t);
    for(int i = 0; i < lcmval / len_s; i++) {
        ss += s;
    }
    for(int i = 0; i < lcmval / len_t; i++) {
        tt += t;
    }
    if(!ss.compare(tt)) cout << 1;
    else cout << 0;
}
