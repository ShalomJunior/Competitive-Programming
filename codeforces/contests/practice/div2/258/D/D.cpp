#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) j++;
        cnt.push_back(j - i + 1);
        i = j + 1;
    }
    int len = cnt.size();
    int e = 0;
    int o = 0;
    int ke = 0;
    int ko = 0;
    for (int i = 0; i < len; i++) {
        if (i & 1) {

        }
        else {

        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
