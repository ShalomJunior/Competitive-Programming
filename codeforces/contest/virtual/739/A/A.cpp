#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> a;
void solve() {
    int n; cin >> n;
    cout << a[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; a.size() < N + 5; i++) {
        if (i % 3 && i % 10 != 3) a.push_back(i);
    }
    int t; cin >> t;
    while (t--)solve();
}