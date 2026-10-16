#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int x = max_element(a.begin(), a.end()) - a.begin();
    int i = x - 1;
    int j = x + 1;
    int cnt = 1;
    for (int h = a[x]; h > 0; h--) {
        while (i >= 0) {
            if (a[i] == h) cnt++, i--;
            else break;
        }
        while (j < n) {
            if (a[j] == h) cnt++, j++;
            else break;
        }
    }
    cout << (cnt == n ? "YES" : "NO") << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
