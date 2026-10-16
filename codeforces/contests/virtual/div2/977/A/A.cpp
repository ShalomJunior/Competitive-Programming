#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;;
    cin >> n;
    vector<int> a(n);
    multiset<int> o, e;
    for (auto& c : a) {
        cin >> c;
        c & 1 ? o.insert(c) : e.insert(c);
    }
    do {

    } while (e.size() + o.size() > 1);
    cout << (e.empty() ? *o.begin() : *e.begin()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}