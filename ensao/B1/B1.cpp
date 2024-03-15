#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string _, a, b;
    getline(cin, _);
    getline(cin, a);
    getline(cin, b);
    string match;
    for (int i = 0; i < N; i++)match += (char)('a' + i);
    match += match;
    cout << "match =  " << match << endl;
    int n = a.size();
    cout << a << " -> " << b << endl;
    cout << "n = " << n << endl;
    string key;
    for (int i = 0; i < n; i++) {
        if (isspace(a[i])) {
            key += '_';
            continue;
        }
        int j = 0;
        while (match[a[i] - 'a' + j] != b[i])j++;
        key += 'a' + j;
    }
    int len = key.size();
    auto go = [&](string r) {
        string p;
        while (p.size() < key.size()) p += r;
        for (int i = 0; i < len; i++) {
            if (p[i] != key[i] && key[i] != '_')return false;
        }
        return true;
        };
    string ans;
    for (int i = 1; i <= len; i++) {
        if (go(key.substr(0, i))) {
            ans = key.substr(0, i);
            break;
        }
    }
    cout << "key = " << key << endl;
    cout << "ans = " << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}