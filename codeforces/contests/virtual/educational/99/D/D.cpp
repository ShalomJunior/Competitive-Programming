#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = INF;
    auto go = [](vector<int> a, vector<int> v, int x) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] <= x && a[i] != v[i]) return INF;
        }
        int use = 0;
        while (!is_sorted(a.begin(), a.end())) {
            use++;
            for (int i = 0; i < n; i++) {
                if (a[i] != v[i]) {
                    if (a[i] > x) {
                        swap(a[i], x);
                    }
                    else {
                        return INF;
                    }
                    break;
                }
            }
        }
        return a == v ? use : INF;
        };
    vector<int> all = a;
    all.push_back(x);
    sort(all.begin(), all.end());
    int m = all.size();
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            if (j != i) {
                temp.push_back(all[j]);
            }
        }
        ans = min(ans, go(a, temp, x));
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}

/*


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dbg(vector<int>& a) {
    for (auto& c : a) cerr << c << " | ";
    cerr << endl;
}
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = INF;
    auto go = [](vector<int> a, vector<int> v, int x) {
        int n = a.size();
        //dbg(a);
        //dbg(v);
        cerr << endl;
        for (int i = 0; i < n; i++) {
            if (a[i] <= x && a[i] != v[i]) return INF;
        }
        cerr << "here" << endl;
        int use = 0;
        while (!is_sorted(a.begin(), a.end())) {
            use++;
            for (int i = 0; i < n; i++) {
                if (a[i] != v[i]) {
                    if (a[i] > x) {
                        swap(a[i], x);
                    }
                    else {
                        return INF;
                    }
                    break;
                }
            }
        }
        cerr << "end" << endl;
        //dbg(a);
        //dbg(v);
        cerr << endl;
        return a == v ? use : INF;
        };
    vector<int> all = a;
    all.push_back(x);
    sort(all.begin(), all.end());
    int m = all.size();
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            if (j != i) {
                temp.push_back(all[j]);
            }
        }
        ans = min(ans, go(a, temp, x));
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
*/