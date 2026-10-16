#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        h[--p[i]] = i;
    }
    int k = 0;
    stringstream ss;
    auto work = [&](int i, int j) {
        swap(p[i], p[j]);
        h[p[i]] = i;
        h[p[j]] = j;
        k++;
        ss << i + 1 << " " << j + 1 << endl;
        };
    for (int i = 0; i < n; i++) {
        if (p[i] == i) continue;
        int j = h[i];
        if (abs(i - j) * 2 >= n) {
            work(i, j);
        }
        else {
            if (i < n / 2) {
                if (j < n / 2) {
                    work(j, n - 1);
                    work(i, n - 1);
                }
                else {
                    work(0, j);
                    work(0, n - 1);
                    work(i, n - 1);
                    work(0, j);
                }
            }
            else {
                work(0, j);
                work(0, i);
                work(0, j);
            }
        }
    }
    assert(k <= 5 * n);
    assert(is_sorted(p.begin(), p.end()));
    cout << k << endl;
    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}