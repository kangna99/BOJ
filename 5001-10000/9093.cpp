#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int tc; cin >> tc;
    cin.ignore();
    for(int t = 1; t <= tc; t++) {
        string sentence;
        getline(cin, sentence);
        sentence += ' ';
        
        stack<char> st;
        for(char c : sentence) {
            if(c == ' ') {
                while(!st.empty()) {
                    cout << st.top(); st.pop();
                }
                cout << c;
            }
            else st.push(c);
        }
        cout << '\n';
    }
}
