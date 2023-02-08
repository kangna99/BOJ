#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int sum;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            sum += arr[j];
        }
    }
    cout << sum;
}
