#include <iostream>
#include <vector>
using namespace std;

vector<char> v[26];

void preorder(char cur) {
    if(cur != '.') {
        cout << cur;
        preorder(v[cur-'A'][0]);
        preorder(v[cur-'A'][1]);
    }
}

void inorder(char cur) {
    if(cur != '.') {
        inorder(v[cur-'A'][0]);
        cout << cur;
        inorder(v[cur-'A'][1]);
    }
}

void postorder(char cur) {
    if(cur != '.') {
        postorder(v[cur-'A'][0]);
        postorder(v[cur-'A'][1]);
        cout << cur;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    char data, left, right;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data >> left >> right;
        v[data-'A'].push_back(left);
        v[data-'A'].push_back(right);
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
}
