#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str; cin >> str;
    int n = str.length();
    vector<char> s(n);
    for (int i = 0; i < n; i++) s[i] = str[i];
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') pre[i]++;
        else pre[i]--;
        if (i) pre[i] += pre[i - 1];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '-' && pre[i] < 0) {
            int ans = -1;
            for (int j = n - 1; j > i; j--) {
                if (s[j] == '+') {
                    swap(s[i], s[j]);
                    ans = j;
                    break;
                }
            }
            int sum = (i ? pre[i - 1] : 0);
            for (int j = i; j < n; j++) {
                sum += (s[j] == '+' ? 1 : -1);
                if (sum < 0) {
                    cout << -1 << endl;
                    return;
                }
            }
            cout << i + 1 << " " << ans + 1 << endl;
            return;
        }
    }
    cout << 1 << " " << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
