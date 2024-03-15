#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (a.empty()) a.push_back(x);
        else {
            if (signbit(a.back()) ^ signbit(x)) a.push_back(x);
            else {
                if (x > a.back()) a.back() = x;
            }
        }
    }
    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}