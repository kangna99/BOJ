#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];
bool visited[9];

void dfs(int level, int num) {
    if(level == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prev = -1;
    for(int i = num; i < n; i++) {
        if(!visited[i] && prev != arr[i]) {
            ans[level] = arr[i];
            prev = arr[i];
            visited[i] = true;
            dfs(level+1, i+1);
            visited[i] = false;
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
    dfs(0, 0);
}
