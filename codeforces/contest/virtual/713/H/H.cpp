#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int>& a, int& l, int& r) {
    int best, curr, start;
    best = curr = start = 0;
    for (int i = 0; i < a.size(); i++) {
        if (curr < 0) { curr = a[i]; start = i; }
        else { curr += a[i]; }
        if (best < curr) {
            l = start; r = i;
            best = curr;
        }
    }
    return best;
}

void solve() {
    int n; cin >> n;
    map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        idx[a].push_back(i);
    }
    int id, S = 0, L = 0, R = 0;
    for (auto& [k, vec] : idx) {
        vector<int> temp;
        for (int i = 0; i < vec.size(); i++) {
            if (i) { temp.push_back(vec[i - 1] - vec[i] + 1); }
            temp.push_back(1);
        }
        int l, r;
        int sum = maximum(temp, l, r);
        l = vec[l / 2]; r = vec[r / 2];
        if (sum > S) { L = l, R = r, id = k, S = sum; }
    }
    cout << id << " " << L + 1 << " " << R + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}