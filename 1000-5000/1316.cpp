#include <iostream>
using namespace std;

int cnt;

bool check(string str) {
    bool alpha[26] = {0, };
    bool result = true;
    for(int i = 0; i < str.size(); i++) {
        int c = str[i]-'a';
        if(!alpha[c]) alpha[c] = true;
        else if(str[i] != str[i-1]) return false;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        string str; cin >> str;
        if(check(str)) cnt++;
    }
    cout << cnt;
}
