#include <iostream>
using namespace std;

int arr[8];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string result = "mixed";
    for(int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    if(arr[0] == 1) {
        for(int i : arr) {
            if(i == arr[i-1]) result = "ascending";
            else {
                result = "mixed";
                break;
            }
        }
    }
    else if(arr[0] == 8) {
        for(int i : arr) {
            if(i == arr[8-i]) result = "descending";
            else {
                result = "mixed";
                break;
            }
        }
    }
    cout << result;
}
