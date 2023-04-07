#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
long long n, m;
long long low, mid, high;

bool check(long long mid) {
    long long sum = 0;
    for(int i : v) {
        if(i % mid == 0) sum += i / mid;
        else sum += i / mid + 1;
    }
    return sum > n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    low = 0; high = *max_element(v.begin(), v.end()) + 1;
    while(low + 1 < high) {
        mid = (low + high) / 2;
        if(check(mid)) low = mid;
        else high = mid;
    }
    cout << high;
}
