#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int x;
    cin >> x;
    vector<int> a(N);
    for (int j = 0; j < N; j++) {
        if (x & (1 << j)) {
            a[j] = 1;
        }
    }
    int minus = 0;
    for (int i = 0; i < N; ) {
        int j = i;
        int s = 0;
        while (a[j]) {
            s += 1 << j;
            j++;
        }
        if (j - i >= 2) {
            minus += (1 << j) - s;
            a[j--] = 1;
            while (j >= i) a[j--] = 0;
        }
        i = j + 1;
    }
    for (int j = 0; j < N; j++) {
        if (minus & (1 << j)) {
            assert(a[j] == 0);
            a[j] = -1;
        }
    }
    cout << N << endl;
    for (auto& c : a) cout << c << " ";
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

const int N = 32;
void solve() {
    int x;
    cin >> x;
    vector<int> a(N);
    for (int j = 0; j < N; j++) {
        if (x & (1 << j)) {
            a[j] = 1;
        }
        cerr << a[j] << " | ";
    }
    cerr << endl;
    int minus = 0;
    for (int i = 0; i < N; ) {
        int j = i;
        int s = 0;
        while (a[j]) {
            s += 1 << j;
            j++;
        }
        if (j - i >= 2) {
            minus += (1 << j) - s;
            a[j--] = 1;
            while (j >= i) a[j--] = 0;
        }
        i = j + 1;
    }
    cerr << "passed" << endl;
    for (int j = 0; j < N; j++) {
        if (minus & (1 << j)) {
            assert(a[j] == 0);
            a[j] = -1;
        }
    }
    int ans = 0;
    for (int j = 0; j < N; j++) {
        ans += (1 << j) * a[j];
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
    assert(ans == x);
    cerr << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/