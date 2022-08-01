#include <iostream>
using namespace std;
int N, M;
int arr[8];
bool visited[8];

void dfs(int depth) {
	if(depth == M) {
		for(int i=1; i<=M; i++) {
			cout << arr[i-1] << " ";	
		}
		cout << "\n";
		return;
	}
	for(int i=1; i<=N; i++) {
		visited[i] == true;
		arr[depth] = i;
		dfs(depth+1);
		visited[i] == false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	dfs(0);
	return 0;
}
