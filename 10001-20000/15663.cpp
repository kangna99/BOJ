#include <iostream>
#include <algorithm>
#define MAX 9
int N, M;
int input[MAX];
int arr[MAX];
bool visited[MAX];
using namespace std;

void dfs(int depth) {
    if(depth == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int last = -1;
    for(int i=0; i<N; i++) {
        if(!visited[i] && input[i] != last) {
            visited[i] = true;
            arr[depth] = input[i];
            dfs(depth+1);
            visited[i] = false;
            last = input[i]; //마지막 수 저장
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
