#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	
	int N;
	cin >> N;
	
	stack<int> st;
	string str;
	
	for(int i=0; i<N; i++) {
		cin >> str;
		
		if(str == "push") { //정수 X를 스택에 넣는 연산 
			int num;
			cin >> num;
			st.push(num);
		}
		else if(str == "pop") { //스택 상위 정수를 빼고 출력. 없으면 -1 
			if(!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		} 
		else if(str == "size") { //스택 사이즈 출력 
			cout << st.size() << '\n';
		}
		else if(str == "empty") { //스택이 비어있으면 1, 아니면 0 출력 
			if(st.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if(str == "top") { //스택 상위 정수를 출력. 없으면 -1 
			if(!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}
	return 0;
}
