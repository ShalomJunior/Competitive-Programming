#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string s;
    s += a[0];
    int j;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            s += b[i];
            j = n - 1;
        }
        else {
            if (a[i + 1] <= b[i])s += a[i + 1];
            else {
                s += b.substr(i, n - i + 1);
                j = i;
                break;
            }
        }
    }
    int cnt = 0;
    while (j > 0 && a[j] == b[j - 1]) {
        j--;
        cnt++;
    }
    cout << s << endl;
    cout << cnt + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}