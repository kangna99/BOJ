#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int N;
	cin >> N;
	
	queue<int> q;
	string str;
	
	for(int i=0; i<N; i++) {
		cin >> str;
		if(str == "push") { //정수를 큐에 넣는 연산 
			int num;
			cin >> num;
			q.push(num);
		}
		else if(str == "pop") { //큐에서 가장 앞 정수를 빼고 출력, 없으면 -1 
			if(!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			} else cout << "-1\n";
		}
		else if(str == "size") { //큐에 들어있는 정수 개수를 출력 
			cout << q.size() << '\n';
		}
		else if(str == "empty") { //큐가 비어있으면 1, 아니면 0 
			if(q.empty()) cout <<"1\n";
			else cout <<"0\n";
		}
		else if(str == "front") { //큐의 가장 앞에 있는 정수 출력, 없으면 -1
			if(!q.empty()) cout << q.front() << '\n';
			else cout <<"-1\n"; 
		}
		else if(str == "back") { //큐의 가장 뒤에 있는 정수 출력, 없으면 -1 
			if(!q.empty()) cout << q.back() << '\n';
			else cout <<"-1\n"; 
		}
	}
	return 0;
}
