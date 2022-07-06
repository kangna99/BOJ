#include <iostream>
using namespace std;

int main(void) {
	int N, temp; 
	int ans = 0;
	cin >> N;
	for(int i=0; i<N; i++) {
		int cnt = 0; 
		cin >> temp;
		for(int j=1; j<=temp; j++) {
			if(temp % j == 0) 
				cnt++; 
		}
		if(cnt==2)
			ans++;
	}
	cout << ans;
	return 0;
}
