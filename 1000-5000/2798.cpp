#include <iostream>
using namespace std;

constexpr int N = 101;
int arr[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, sum = 0, maxval = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m) maxval = max(maxval, sum);
            }
        }
    }
    cout << maxval;
}
