#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int x;
    cin >> x;
    string bin;
    for (int j = N; j >= 0; j--) {
        if (x & (1 << j)) {
            bin += '1';
        }
        else {
            bin += '0';
        }
    }
    int j = 0;
    while (bin[j] == '0') j++;
    bin = bin.substr(j, N + 1 - j);
    int m = bin.length();
    j = m - 1;
    int M = 1;
    while (j - 1 >= 0 && bin[j - 1] == bin[j]) j--, M *= 2;
    if (j == 0) {
        cout << -1;
    }
    else {
        int ans = M + M * 2;
        cout << (ans < x ? ans : -1);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}