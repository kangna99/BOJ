#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int n;
// string str;
// vector<string> v[51];

// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cin >> str;
//         v[str.size()].push_back(str);
//     }
//     for(auto &s: v) {
//         sort(s.begin(), s.end());
//         s.erase(unique(s.begin(), s.end()), s.end());
//         for(string const &ss: s)
//             cout << ss << '\n';
//     }
// }

int n;
string str;
vector<string> v;

bool compare(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto const &s : v) {
        cout << s << '\n';
    }
}
