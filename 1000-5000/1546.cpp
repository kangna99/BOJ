#include <iostream>
using namespace std;

double score[1001];

int main() {
    int n, maxval = 0;
    double sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> score[i];
        if(maxval < score[i]) maxval = score[i];
    }
    for(double &j : score) {
        j = j / maxval * 100;
        sum += j;
    }
    cout << fixed;
    cout.precision(6);
    cout << sum / n;
}