#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int M, N;
	bool *prime; 
	cin >> M >> N;
	prime = new bool[N+1];
	//true로 배열 초기화 
	for(int i=M; i<=N; i++){
		prime[i] = true;
	}
	//배수라면 false로 수정
	//에라토스테네스의 체 
	prime[1] = false;
	for(int i=2; i<=sqrt(N); i++) {
		for(int j = i+i; j<=N; j+=i) {
			prime[j] = false;
		}
	}
	//true인 값들만 출력 
	for(int i=M; i<=N; i++) {
		if(prime[i])
			cout << i << "\n";
	}
	return 0;
}
