#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	stack<int> st;
	string ans;
	int n, max = 0;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		while(num > max) {
			st.push(++max);
			ans += '+';
		}
		if((!st.empty()) && st.top() == num) {
			st.pop();
			ans += '-';
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for(int j=0; j<ans.length(); j++) {
		cout << ans[j] << '\n';
	}
	return 0;
}
