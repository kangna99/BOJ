#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool VPS(string str) {
	stack<char> st;
	for(int j=0; j<str.length(); j++) {
		if(str[j]=='(') st.push(str[j]);
		else {
			if(!st.empty()) st.pop();
			else return false;
		}
	}
	return st.empty(); //최종적으로 스택이 비어있어야 true 
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++) {
		string str;
		cin >> str;
		
		if(VPS(str)) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
