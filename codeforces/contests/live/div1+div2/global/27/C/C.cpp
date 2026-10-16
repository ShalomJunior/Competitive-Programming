#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    if (n & 1) {
        cout << n << endl;
    }
    else {
        int j = N;
        while ((n & (1 << j)) == 0) j--;
        int k = (1 << (j + 1)) - 1;
        cout << k << endl;
        set<int> s(p.begin(), p.end());
        p[n - 1] = n;
        if (s.count(k))
            p[n - 2] = k;
        else
            p[n - 2] = (1 << j) - 1;
        p[n - 3] = p[n - 2] - 1;
        s.erase(p[n - 1]);
        s.erase(p[n - 2]);
        s.erase(p[n - 3]);
        for (int i = 0; i < n - 3; i++) {
            p[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    swap(p[0], p[1]);
    for (auto& c : p) cout << c << " ";
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
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    map <int, vector<vector<int>>> h;
    int z = 0;
    do {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                k = k | p[i];
            }
            else {
                k = k & p[i];
            }
        }
        h[k].push_back(p);
        z = max(z, k);
    } while (next_permutation(p.begin(), p.end()));
    cout << "z = " << z << endl;
    for (auto& c : h[z][0]) {
        cerr << c << " -> ";
    }
    cerr << endl;
    // for (auto& ls : h[z]) {
    //     for (auto& c : ls) cerr << c << " -> ";
    //     cerr << endl;
    // }
    int t; cin >> t;
    while (t--)solve();
}*/