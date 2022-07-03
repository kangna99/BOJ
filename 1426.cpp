#include <iostream>
using namespace std;

int main(void) {
	int ans = 0;
	int cnt = 0;
	int n, temp;
	
	cin >> n;
	
	while(cnt != n) {
		ans++;
		temp = ans;
		while(temp != 0) {
			if(temp % 1000 == 666) {
				cnt++;
				break;
			}
			else temp /= 10;
		}	
	}
	cout << ans;
	return 0;
}
