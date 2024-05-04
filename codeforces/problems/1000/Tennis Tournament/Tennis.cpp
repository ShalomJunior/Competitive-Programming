#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, p;
    cin >> n >> b >> p;
    int bot = 0;
    int  tow = n * p;
    while (n != 1) {
        int matches = pow(2, -1 + (int)log2(n));
        bot += matches * (2 * b + 1);
        n = matches + (n - 2 * matches);
    }
    cout << bot << " " << tow << endl;
}