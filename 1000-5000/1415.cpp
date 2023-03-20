#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
constexpr int N = 5e5+5;
bool isPrime[N];
long long dp[N];
int arr[10001];
int n, sum;

long long solve() {
    long long ans = 0;
    dp[0] = 1;
    for(auto [val, cnt] : v) {
        for(int i = n * 10000; i >= 0; i--) {
            for(int j = 1; j <= cnt; j++) {
                if(i - val * j < 0) break;
                dp[i] += dp[i - val * j];
            }
        }
    }
    for(int i = 2; i <= n * 10000; i++) {
        if(isPrime[i]) ans += dp[i];
    }
    return ans * (arr[0] + 1);
}

void getPrimes(int sum) {
    fill(isPrime, isPrime+sum+1, 1);
    isPrime[1] = false;
    for(int i = 2; i <= sum; i++) {
        if(isPrime[i]) {
            for(int j = i + i; j <= sum; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[a]++;
        sum += a;
    }
    for(int i = 1; i <= 10000; i++) {
        if(arr[i]) v.push_back({i, arr[i]});
    }
    getPrimes(sum);
    cout << solve();
}
