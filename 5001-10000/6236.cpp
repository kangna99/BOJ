#include <iostream>
using namespace std;

constexpr int N = 1e5+5;
int money[N];
int n, m;

bool check(int mid) {
    int curMoney = 0; int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(money[i] > mid) return false;
        if(money[i] > curMoney) curMoney = mid, cnt++;
        curMoney -= money[i];
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int low, mid, high, sum = 0, ans;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> money[i];
        sum += money[i];
    }
    low = 1; high = sum;
    while(low <= high) {
        mid = (low + high) / 2;
        if(check(mid)) {
            high = mid - 1;
            ans = mid;
        }
        else low = mid + 1;
    }
    cout << ans;
}
