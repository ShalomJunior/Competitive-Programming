#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const string L = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n; string s;
    cin >> n >> s;

    set<char> child(L.begin(), L.end());
    set<char> parent(L.begin(), L.end());

    vector<bool> done(26);
    vector<pair<char, char>> link(26);
    for (auto& c : s) {
        int i = c - 'a';
        if (done[i])continue;
        child.erase(c);
        parent.erase(c);
        char t = link[i].S;
        parent.erase(t);
        char p = *parent.begin();
        //cout << "c = " << c << " p = " << p << endl;
        parent.erase(p);
        link[i].F = p;
        link[p - 'a'].S = c;
        parent.insert(c);
        if (t != '\0') parent.insert(t);
        done[i] = true;
    }

    string ans;
    for (auto& c : s) ans += link[c - 'a'].F;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}