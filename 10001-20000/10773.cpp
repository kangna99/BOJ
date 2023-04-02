#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int k; cin >> k;
    vector<int> v;
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        if(a == 0) v.pop_back();
        else v.push_back(a);
    }
    int sum = 0;
    for(int i : v) {
        sum += i;
    }
    cout << sum;
}
