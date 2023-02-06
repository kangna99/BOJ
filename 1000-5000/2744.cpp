#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    for(char &c : str) {
        c ^= 32;
    }
    cout << str;
}