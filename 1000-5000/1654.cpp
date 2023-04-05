#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
long long low = 0, mid, high = 1e10;
int k, n;

bool check(long long mid) {
    long long sum = 0;
    for(int i : v) sum += i / mid;
    return sum >= n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    while(low + 1 < high) {
        mid = (low + high) / 2;
        if(check(mid)) low = mid;
        else high = mid;
    }
    cout << low;
}
