#include <bits/stdc++.h>
using namespace std;

int mex(int a, int b) {
    if (min(a, b) > 0) return 0;
    if (max(a, b) == 1) return 2;
    return 1;
}

void L(deque<int>& a, vector<pair<int, int>>& o) {
    if (a[0] == 0) {
        o.push_back({ 0, 1 });
        int nxt = mex(a[0], a[1]);
        a.pop_front();
        a.pop_front();
        a.push_front(nxt);
    }
}

void R(deque<int>& a, vector<pair<int, int>>& o) {
    int n = a.size();
    if (a.back() == 0) {
        o.push_back({ n - 2, n - 1 });
        int nxt = mex(a[n - 2], a[n - 1]);
        a.pop_back();
        a.pop_back();
        a.push_back(nxt);
    }
}

void M(deque<int>& a, vector<pair<int, int>>& o) {
    int n = a.size();
    int j = 0;
    while (j < n && a[j]) j++;
    if (j < n) {
        o.push_back({ j, n - 1 });
        o.push_back({ 0, j });
    }
    else if (n > 1) {
        o.push_back({ 0, n - 1 });
    }
}

void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (auto& c : a) cin >> c;
    vector<pair<int, int>> o;
    L(a, o);
    R(a, o);
    M(a, o);
    cout << o.size() << endl;
    for (auto& [l, r] : o) {
        cout << l + 1 << " " << r + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
