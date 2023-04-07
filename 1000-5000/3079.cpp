#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;
long long low, mid, high;

bool check(long long mid) {
    long long sum = 0;
    for(int i : v) {
        sum += (mid / i);
        if(sum >= m) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    low = 0; high = 1e18;
    while(low + 1 < high) {
        mid = (low + high) / 2;
        if(!check(mid)) low = mid;
        else high = mid;
    }
    cout << high;
}
