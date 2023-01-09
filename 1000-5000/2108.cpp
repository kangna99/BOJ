#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

constexpr int N = 5e5+5;
int arr[N], cnt[N];
int n, meanval, medianval, modeval, rangeval, maxval;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i] + 4000]++;
    }
    sort(arr, arr + n);
    for(int i = 0; i < 8001; i++) {
        if(cnt[i] > maxval) {
            maxval = cnt[i];
            v.clear();
            v.push_back(i);
        }
        else if(cnt[i] == maxval) {
            v.push_back(i);
        }    
    }
    if(v.size() > 1) {
        for(int &num : v) {
            num -= 4000;
        }
        sort(v.begin(), v.end());
        modeval = v[1];
    }
    else {
        modeval = v[0] - 4000;
    }
    meanval = round(accumulate(arr, arr+n, 0.0) / n);
    medianval = arr[n/2];
    rangeval = arr[n-1] - arr[0];

    printf("%d\n%d\n%d\n%d", meanval, medianval, modeval, rangeval);
}
