#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c; cin >> n >> c;
    vector<int>v(n);
    for (auto& c : v)
        cin >> c;

    int best = 0;
    for (int i = 0; i < n - 1; i++) {
        int h = v[i] - v[i + 1] - c;
        best = max(best, h);
    }
    cout << best << endl;
}