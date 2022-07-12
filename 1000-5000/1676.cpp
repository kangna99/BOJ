#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int N, ans = 0;
	cin >> N;
	//5^1의 배수 개수 + 5^2의 배수 개수 + 5^3의 배수 개수 + ... 
	for(int i=5; i<=N; i*=5) {
		ans += N/i;
	}
	cout << ans;
	return 0;
}
