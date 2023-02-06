#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int alphabet[26];
    memset(alphabet, -1, sizeof(alphabet));
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        int idx = str[i] - 'a';
        if(alphabet[idx] == -1) alphabet[idx] = i;
    }
    for(int c : alphabet) cout << c << ' ';
}