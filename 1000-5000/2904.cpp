#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int N = 1e6+6;
bool isPrime[N];
vector<int> primes;

void getPrimes() {
    for (int i = 2; i <= N; i++) {
        if(!isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= N; j += i) {
                isPrime[j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    getPrimes();
    int n; cin >> n;
    vector<int> cnt(primes.size(), 0);
    vector<vector<int>> c(n, vector<int>(primes.size(), 0));
    
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        for (int j = 0; j < primes.size() && primes[j] <= num; j++) {
            while (num % primes[j] == 0) {
                num /= primes[j];
                cnt[j]++;
                c[i][j]++;
            }
        }
    }

    int gcd = 1; int count = 0;
    for(int i = 0; i < primes.size(); i++) {
        int exp = cnt[i] / n;
        gcd *= pow(primes[i], exp);
        for(int j = 0; j < n; j++) {
            if(c[j][i] < exp) count += exp - c[j][i];
        }
    }
    cout << gcd << ' ' << count;
}
