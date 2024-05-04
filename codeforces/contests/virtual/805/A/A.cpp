#include <bits/stdc++.h>
using namespace std;

vector<int> p;
void prepare() {
    for (int i = 0; i < 10; i++) {
        p.push_back(pow(10, i));
    }
}

void solve() {
    int n; cin >> n;
    auto it = upper_bound(p.begin(), p.end(), n);
    cout << (n - ((it == p.begin()) ? 1 : *(--it))) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}