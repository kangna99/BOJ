#include <iostream>
#include <cmath>
using namespace std;

long long low, mid, high;
long long n;

bool check(long long mid) {
    return mid * mid < n;
}

int main() {
    cin >> n;
    low = -1;
    high = sqrt(n) + 1;
    while(low + 1 < high) {
        mid = (low + high) / 2;
        if(check(mid)) low = mid;
        else high = mid;
    }
    cout << high;
}
