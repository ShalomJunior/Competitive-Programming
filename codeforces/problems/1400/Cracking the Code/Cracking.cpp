#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e5;

long long shuffle() {
    string s; cin >> s;
    string ans;
    ans += s[0]; ans += s[2];
    ans += s[4]; ans += s[3];
    ans += s[1];

    return stoi(ans);
}

int main() {
    long long n = shuffle();
    long long md = n;
    for (int i = 1; i < 5; i++) {
        n *= md;
        n %= MOD;
    }

    if (n == 0) {
        cout << "00000" << endl;
        return 0;
    }
    cout << n << endl;
}