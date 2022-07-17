#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	for(int i=0; i<t; i++) {
		long long ans = 0;
		cin >> n;
		int arr[n];
		for(int j=0; j<n; j++) {
			cin >> arr[j];
		}
		for(int j=0; j<n; j++) {
			for(int k=j+1; k<n; k++) {
				ans += gcd(arr[j], arr[k]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
