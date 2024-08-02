#include <bits/stdc++.h>
using namespace std;

string sub(string a, string b) {
    bool neg = false;
    if (a == b) {
        return "0";
    }
    else if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        swap(a, b);
        neg = true;
    }

    string res = "";
    int carry = 0;
    int n1 = a.length();
    int n2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n2; i++) {
        int sub = (a[i] - '0') - (b[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        res.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++) {
        int sub = (a[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        res.push_back(sub + '0');
    }

    while (res.length() > 1 && res.back() == '0') res.pop_back();

    if (neg) res.push_back('-');

    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string p;
    if (s[0] < '9') {
        p = string(n, '9');
    }
    else {
        p = string(n + 1, '1');
    }
    cout << sub(p, s) << endl;;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}