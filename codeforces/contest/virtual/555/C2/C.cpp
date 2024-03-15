#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto& c : vec) cin >> c;
    sort(vec.begin(), vec.end());
    vector<int> asc, desc;
    set<int> a, d;
    for (int i = 0; i < n; i++) {
        if (asc.empty() || (!asc.empty() && asc.back() < vec[i] && !a.count(vec[i]))) {
            asc.push_back(vec[i]);
        }
        else if (desc.empty() || (!desc.empty() && desc.back() < vec[i] && !d.count(vec[i]))) {
            desc.push_back(vec[i]);
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << asc.size() << endl;
    for (auto& c : asc) cout << c << " ";
    cout << endl;
    cout << desc.size() << endl;
    for (int i = desc.size() - 1; i >= 0; i--) cout << desc[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}