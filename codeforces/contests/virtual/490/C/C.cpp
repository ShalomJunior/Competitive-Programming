#include <bits/stdc++.h>
using namespace std;

const int L = 26;
void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> a(L);
    for (auto& c : s) a[c - 'a']++;
    char let; int del;
    for (int i = 0; i < L; i++) {
        if (k > a[i]) k -= a[i];
        else {
            let = 'a' + i;
            del = k;
            break;
        }
    }
    string ans;
    for (auto& c : s) {
        if (c < let) continue;
        else if (c == let && del) del--;
        else ans += c;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}