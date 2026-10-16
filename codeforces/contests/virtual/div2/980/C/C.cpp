#include <bits/stdc++.h>
using namespace std;

const int N = 2;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(N));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](const int& i, const int& j) {
        int x = min(a[i][0], a[i][1]);
        int y = min(a[j][0], a[j][1]);
        if (x != y) return x < y;
        return max(a[i][0], a[i][1]) < max(a[j][0], a[j][1]);
        });
    for (auto& c : p) {
        cout << a[c][0] << " " << a[c][1] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}



/*

#include <bits/stdc++.h>
using namespace std;

const int N = 2;

int work(vector<int> a) {
    int m = a.size();
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) cnt++;
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(N));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    map<int, vector<vector<int>>> h;
    do {
        vector<int> b;
        for (auto& c : p) {
            b.push_back(a[c][0]);
            b.push_back(a[c][1]);
        }
        h[work(b)].push_back(b);
    } while (next_permutation(p.begin(), p.end()));
    int mn = h.begin()->first;
    for (auto& v : h[mn]) {
        for (auto& c : v) cerr << c << "->";
        cerr << endl;
    }
    cerr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/