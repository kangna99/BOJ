#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define endl '\n'
using namespace std;

unordered_set<string> neverSeen;
vector<string> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    string name;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> name;
        neverSeen.insert(name);
    }
    for(int i = 0; i < m; i++) {
        cin >> name;
        if(neverSeen.find(name) != neverSeen.end()) ans.push_back(name);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(string s : ans) cout << s << endl;
}
