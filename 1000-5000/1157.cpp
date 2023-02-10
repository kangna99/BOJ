#include <iostream>
using namespace std;

int arr[26];
int maxval, maxidx, cnt;

int main() {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') str[i] ^= 32;
        arr[str[i]-'A']++;
    }
    for(int i = 0; i < 26; i++) {
        if(maxval < arr[i]) {
            maxval = arr[i];
            maxidx = i;
            cnt = 1;
        }
        else if(maxval == arr[i]) cnt++;
    }
    if(cnt > 1) printf("?");
    else printf("%c", maxidx+'A');
}
