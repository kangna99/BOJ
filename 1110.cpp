#include <iostream>
using namespace std;

int main(void) {
	int n, m, temp;
	int cnt = 0;
	cin >> n;
	m = temp = n;
	while(1) {
		cnt ++;
		if(m >= 10) {
			temp = m/10 + m%10;
		}
		m = (m%10)*10 + temp%10;
		
		if(n == m)
			break;
	}
	cout << cnt << endl;
	return 0;
}
