#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	deque<int> dq;
	int N;
	string str;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> str;
		if(str == "push_front") {
			int num;
			cin >> num;		
			dq.push_front(num);
		}
		else if(str == "push_back") {
			int num;
			cin >> num;		
			dq.push_back(num);
		}
		else if(str == "pop_front") {
			if(!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		else if(str == "pop_back") {
			if(!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else cout << "-1\n";
		}
		else if(str == "size") {
			cout << dq.size() << '\n';
		}
		else if(str == "empty") {
			if(dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if(str == "front") {
			if(!dq.empty()) cout <<dq.front() << '\n';
			else cout << "-1\n";
		}
		else if(str == "back") {
			if(!dq.empty()) cout <<dq.back() << '\n';
			else cout << "-1\n";
		}
	}
	return 0;
}
