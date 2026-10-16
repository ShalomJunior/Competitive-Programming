#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 63;
vector<int> mask(N, 1);

int get(vector<int>& b) {
    int n = b.size();
    auto a = b;
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans |= mask[i];
        }
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        if (n & mask[i]) {
            b[i] = 1;
        }
    }
    for (int len = N - 2; mask[len + 1] - 1 >= n; len--) {
        vector<int> a(len + 1);
        a[len] = 1;
        int i = 0;
        int j = len;
        bool f = true;
        while (i <= j) {
            if (b[j]) {
                if (i == j) {
                    f = false;
                    break;
                }
                a[j] = 1;
                a[i] = 0;
            }
            else {
                a[i] = a[j] = 0;
            }
            i++;
            j--;
        }
        if (f && get(a) == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) mask[i] = mask[i - 1] * 2;
    int t; cin >> t;
    while (t--)solve();
}

/*

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 50;
vector<int> mask(N, 1);
int f(int x) {
    vector<int> b;
    while (x) {
        b.push_back(x % 2);
        x /= 2;
    }
    auto a = b;
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            ans |= (1 << i);
        }
    }
    return ans;
}

int get(vector<int>& b) {
    int n = b.size();
    auto a = b;
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans |= mask[i];
        }
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        if (n & mask[i]) {
            b[i] = 1;
        }
    }
    for (int len = N - 2; mask[len + 1] - 1 >= n; len--) {
        vector<int> a(len + 1);
        a[len] = 1;
        int i = 0;
        int j = len;
        bool f = true;
        while (i <= j) {
            if (b[j]) {
                if (i == j) {
                    f = false;
                    break;
                }
                a[j] = 1;
                a[i] = 0;
            }
            else {
                a[i] = a[j] = 0;
            }
            i++;
            j--;
        }
        if (f && get(a) == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) mask[i] = mask[i - 1] * 2;
    for (int i = 1; i <= 5000; i++) {
        if (f(i) == 10) {
            cout << i << endl;
        }
    }
    cout << endl;
    int t; cin >> t;
    while (t--)solve();
}

*/