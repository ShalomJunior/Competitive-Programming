#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (auto& c : v)cin >> c;
    sort(v.begin(), v.end());

    if (x <= v[0]) {
        cout << "Yes" << endl;
        return;
    }

    cout << ((x > v[0]) ? "No" : "Yes") << endl;
}