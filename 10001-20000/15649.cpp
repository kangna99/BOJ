#include <iostream>
#define MAX 9
using namespace std;
int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int depth) {
	if(depth == M) {
		for(int i=0; i<M; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
	else {
		for(int i=1; i<=N; i++) {
			if(!visited[i]) {
				visited[i] = true;
				arr[depth] = i;
				dfs(depth+1);
				visited[i] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	dfs(0);
	return 0;
}
