#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int k;
    string s;
    cin >> k >> s;
    for (auto c : { '1', '4', '6', '8', '9' }) {
        for (int i = 0; i < k; i++) {
            if (s[i] == c) {
                cout << 1 << endl;
                cout << s[i] << endl;
                return;
            }
        }
    }
    for (auto& c : { '2', '3', '5', '7' }) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += (s[i] == c);
        }
        if (cnt >= 2) {
            cout << 2 << endl;
            cout << c << c << endl;
            return;
        }
    }
    vector<string> a;
    for (int i = 1; i < (1 << k); i++) {
        string t;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) t += s[j];
        }
        a.push_back(t);
    }
    sort(a.begin(), a.end(), [&](const string& a, const string& b) {
        return a.size() < b.size();
        });
    for (auto& t : a) {
        if (!is_prime(stoi(t))) {
            cout << t.size() << endl;
            cout << t << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
