#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5;
int mx[N];
void init() {
    mx[0] = 0;
    for (int i = 1; i < N; i++) {
        mx[i] = mx[i - 1] + i;
        if (mx[i] & 1) mx[i]--;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k & 1 || k > mx[n]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int j = 0;
    while (mx[j + 1] < k) j++;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    reverse(p.begin(), p.begin() + j);
    int d = mx[j];
    for (int i = 0; d != k && i < n - 1; i++) {
        int nd = d - abs(p[i] - (i + 1)) - abs(p[n - 1] - n) + abs(p[n - 1] - (i + 1)) + abs(p[i] - n);
        if (nd == k) {
            swap(p[i], p[n - 1]);
            break;
        }
    }
    for (auto& c : p) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}

// void test() {
//     int n;
//     cin >> n;
//     vector<int> p(n);
//     iota(p.begin(), p.end(), 1);
//     set<int> all;
//     do {
//         int s = 0;
//         for (int i = 0; i < n; i++) {
//             s += abs(p[i] - (i + 1));
//         }
//         cerr << endl;
//         cerr << s << " ";
//         all.insert(s);
//     } while (next_permutation(p.begin(), p.end()));
//     cerr << endl;
//     for (int i = 0; i < n * n; i++) {
//         if (!all.count(i)) {
//             cout << i << " ";
//         }
//     }
//     cout << endl;
// }