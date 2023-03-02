#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void dfs(int level) {
    if(level == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prev = -1;
    for(int i = 0; i < n; i++) {
        if(prev != arr[i]) {
            ans[level] = arr[i];
            prev = arr[i];
            dfs(level+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    dfs(0);
}
