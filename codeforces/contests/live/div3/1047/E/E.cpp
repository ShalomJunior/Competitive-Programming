#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int>& a) {
    int n = a.size();
    map<int, int> h;
    for (auto& c : a) h[c]++;
    int mex = 0;
    while (h[mex] > 0) mex++;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < mex) {
            if (h[a[i]] > 1) res[i] = mex;
            else res[i] = a[i];
        }
        else {
            res[i] = mex;
        }
    }
    return res;
}

void show(vector<int>& a) {
    for (auto& c : a) cerr << c << " ";
    cerr << endl;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < min(k, 8); i++) {
        a = fun(a);
        //show(a);
    }
    if (k <= 8) {
        cout << accumulate(a.begin(), a.end(), 0LL);
    }
    else {
        int u = min(k, 8);
        auto f = a;
        auto g = fun(a);
        cout << (k & 1 ? accumulate(g.begin(), g.end(), 0LL) : accumulate(f.begin(), f.end(), 0LL));
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
