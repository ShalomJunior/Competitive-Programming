#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int f(int n, int k) {
    int m = n / k;
    return (m * k == n) ? m : m + 1;
}
void solve() {
    string s; int p; cin >> s >> p;
    vector<int> arr(N);
    int cnt = 0;
    for (auto& c : s) {
        arr[c - 'a']++;
        cnt += (c - 'a') + 1;
    }
    if (cnt <= p) { cout << s << endl; return; }
    for (int i = N - 1; i >= 0; i--) {
        if (cnt - (i + 1) * arr[i] >= p) {
            cnt -= (arr[i] * (i + 1));
        }
        else {
            int skip = f(cnt - p, i + 1);
            for (auto& c : s) {
                if (c - 'a' <= i) {
                    if (c - 'a' == i && skip)skip--;
                    else cout << c;
                }
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}