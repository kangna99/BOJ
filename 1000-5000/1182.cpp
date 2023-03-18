#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    int n, s; cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    int cnt = 0;

    for(int i = 1; i < (1 << n); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) sum += v[j];
        }
        if(sum == s) cnt++;
    }
    cout << cnt;
}
