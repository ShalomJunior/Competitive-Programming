// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;
// void solve() {
//     int n, x, y;
//     cin >> n >> x >> y;
//     --x;
//     --y;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         if (i % 2 == 0) a[i] = 1;
//     }
//     if (n & 1) a[0] = 2;
//     if (a[x] == a[y]) a[x] = 2;
//     for (auto& c : a) cout << c << " ";
//     cout << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     while (t--)solve();
// }


#include <bits/stdc++.h>
using namespace std;

const int N = 20;
uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

void solve() {
    int n = rng() % N + 1;
    int x = rng() % n + 1;
    int y = rng() % n + 1;
    //cin >> n >> x >> y;
    if (x > y) swap(x, y);
    if (n < 3 || x == y) return;
    --x;
    --y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a[i] = 1;
    }
    if (n & 1) a[0] = 2;
    auto f = [&](int i) {
        set<int> s;
        s.insert(a[(i + 1) % n]);
        s.insert(a[(i == 0 ? n - 1 : i - 1)]);
        int mx = 0;
        while (s.count(mx)) mx++;
        return mx;
        };

    if (a[x] == a[y]) {
        a[x] = 1 - a[x];
        a[(x + 1) % n] = 2;
        a[(x - 1 + n) % n] = 2;
    }
    a[0] = f(0);
    for (int i = 0; i < n; i++) {
        set<int> s;
        s.insert(a[(i + 1) % n]);
        s.insert(a[(i == 0 ? n - 1 : i - 1)]);
        if (i == x) s.insert(a[y]);
        if (i == y) s.insert(a[x]);
        int mx = 0;
        while (s.count(mx)) mx++;
        if (a[i] != mx) {
            cerr << "flop " << i << endl;
            cerr << a[i] << " " << mx << endl;
            cerr << n << " " << x << " " << y << endl;
            for (auto& c : a) cout << c << " ";
            cout << endl;
            assert(false);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
