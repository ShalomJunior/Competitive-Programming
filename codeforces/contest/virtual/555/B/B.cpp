#include <bits/stdc++.h>
using namespace std;

const int D = 10;
void solve() {
    int n; string s;
    cin >> n >> s;
    vector<int> a(D);
    for (int i = 1; i < D; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int d = s[i] - '0';
        if (d < a[d]) {
            for (int j = i; j < n; j++) {
                int c = s[j] - '0';
                if (c > a[c]) break;
                s[j] = a[c] + '0';
            }
            break;
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}