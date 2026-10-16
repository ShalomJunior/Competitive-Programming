#include<bits/stdc++.h>
using namespace std;

vector<int> kmp_table(const vector<int>& p) {
    int n = p.size();
    vector<int> table(n);
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && p[i] != p[k]) k = table[k - 1];
        if (p[i] == p[k]) k++;
        table[i] = k;
    }
    return table;
}

vector<int> kmp(vector<int>& s, vector<int>& p) {
    int m = s.size();
    int n = p.size();
    auto table = kmp_table(p);
    vector<int> id;
    int k = 0;
    for (int i = 0; i < m; i++) {
        while (k > 0 && s[i] != p[k]) k = table[k - 1];
        if (s[i] == p[k])k++;
        if (k == n) {
            id.push_back(i - n + 1);
            k = table[k - 1];
        }
    }
    return id;
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(w);
    for (auto& c : b) cin >> c;
    if (w == 1) {
        cout << n << endl;
        return;
    }
    vector<int> na;
    for (int i = 1; i < n; i++) {
        na.push_back(a[i] - a[i - 1]);
    }
    vector<int> nb;
    for (int i = 1; i < w; i++) {
        nb.push_back(b[i] - b[i - 1]);
    }
    cout << kmp(na, nb).size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}