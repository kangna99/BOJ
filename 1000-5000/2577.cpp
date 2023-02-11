#include <iostream>
using namespace std;

int cnt[10];
int a, b, c;

int main() {
    cin >> a >> b >> c;
    string result = to_string(a*b*c);
    for(char const &c : result) cnt[c-'0']++;
    for(int i : cnt) cout << i << '\n';
}