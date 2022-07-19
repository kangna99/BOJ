#include <iostream>
#define MAX 9
using namespace std;
int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int depth) {
	if(depth == M) { //배열 다 채우면 출력
		for(int i=0; i<M; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
	else {
		for(int i=1; i<=N; i++) {
			if(!visited[i]) { //아직 방문하지 않은 수라면
				visited[i] = true; //방문 기록
				arr[depth] = i; //배열에 넣음
				dfs(depth+1); //다음 수 정하기
				visited[i] = false; //방문 기록 지움
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	dfs(0); //처음(0번째) 수 정하기
	return 0;
}
