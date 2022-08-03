#include <iostream>
#include <algorithm>
#define MAX 8
int N, M;
int input[MAX];
int arr[MAX];
using namespace std;

void dfs(int depth) {
    if(depth == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=0; i<N; i++) {
            arr[depth] = input[i];
            dfs(depth+1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> input[i];
    }
    sort(input, input+N);
    dfs(0);
}
