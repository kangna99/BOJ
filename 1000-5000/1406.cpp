#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	string str;
	int M;
	cin >> str >> M;
	list<char> l(str.begin(), str.end()); //문자열을 리스트로 변환 
	auto cursor = l.end();
	
	for(int i=0; i<M; i++) {
		char cmd;
		cin >> cmd;
		if(cmd == 'L') {
			if(cursor != l.begin()) cursor--; 
		}
		else if(cmd == 'D') {
			if(cursor != l.end()) cursor++;
		}
		else if(cmd == 'B') {
			if(cursor != l.begin()) {
				cursor--;
				cursor = l.erase(cursor);	
			}
		}
		else if(cmd == 'P') {
			char ch;
			cin >> ch;
			l.insert(cursor, ch);
		}
	}
	for(auto c : l) cout << c;
	return 0;
}
