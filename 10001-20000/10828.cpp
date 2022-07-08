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
		
		if(str == "push") { //���� X�� ���ÿ� �ִ� ���� 
			int num;
			cin >> num;
			st.push(num);
		}
		else if(str == "pop") { //���� ���� ������ ���� ���. ������ -1 
			if(!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		} 
		else if(str == "size") { //���� ������ ��� 
			cout << st.size() << '\n';
		}
		else if(str == "empty") { //������ ��������� 1, �ƴϸ� 0 ��� 
			if(st.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if(str == "top") { //���� ���� ������ ���. ������ -1 
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
