#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int N = 4e6+6;
bool isPrime[N];
vector<int> primeNum;

void getPrime(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) primeNum.push_back(i);
        for(int j = i + i; j <= n; j+=i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    } 
    fill(isPrime, isPrime+n+1, 1);
    getPrime(n);
    int l = 0, r = 0, ans = 0, sum = primeNum[0];
    while(l <= r && r < primeNum.size()) {
        if(sum == n) {
            ans++;
            sum += primeNum[++r];
        }
        else if(sum > n) sum -= primeNum[l++];
        else sum += primeNum[++r];
    }
    cout << ans;
}
