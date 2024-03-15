#include <bits/stdc++.h>

using namespace std;

int ask(int s, int e) {
    int n = e - s + 1;
    cout << "? " << n << " ";
    for (int i = s; i <= e; i++)cout << i << " ";
    cout << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n), cum(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (!i)cum[i] = v[i];
        else cum[i] = cum[i - 1] + v[i];
    }

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int amid = ask(l + 1, mid + 1);
        int eq = cum[mid] - ((!l) ? 0 : cum[l - 1]);
        if (amid != eq) r = mid;
        else l = mid + 1;
    }
    cout << "! " << l + 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}