#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    string t;
    cin >> m >> t;
    bool n = true;
    bool s = true;
    bool e = false;
    bool w = false;
    pair<int, int> H, R;
    string ans;
    for (auto& c : t) {
        if (c == 'N') {
            ans += (n ? 'H' : 'R');
            n ? H.second++ : R.second++;
            n = !n;
        }
        else if (c == 'S') {
            ans += (s ? 'H' : 'R');
            s ? H.second-- : R.second--;
            s = !s;
        }
        else if (c == 'E') {
            ans += (e ? 'H' : 'R');
            e ? H.first++ : R.first++;
            e = !e;
        }
        else {
            ans += (w ? 'H' : 'R');
            w ? H.first-- : R.first--;
            w = !w;
        }
    }
    int a = count(ans.begin(), ans.end(), 'H');
    int b = count(ans.begin(), ans.end(), 'R');
    cout << (H != R || a == 0 || b == 0 ? "NO" : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
