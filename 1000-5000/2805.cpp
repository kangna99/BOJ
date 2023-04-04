#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
long long low = 0, mid, high = 2000000000;
int n, m;

bool check(long long mid) {
    long long sum = 0;
    for(int i : v) {
        if(i - mid > 0) sum += (i - mid);
    }
    return sum >= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    while(low + 1 < high) {
        mid = (low + high) / 2;
        if(check(mid) == check(low)) low = mid;
        else high = mid;
    }
    cout << low;
}
