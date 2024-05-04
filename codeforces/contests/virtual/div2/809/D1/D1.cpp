#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int N = *max_element(a.begin(), a.end());
    auto check = [&](int l, int r) {
        for (int j = 0; j < n; j++) {
            if (a[j] < l) return false;
            if (a[j] <= r) continue;
            if (r == 0) {
                if (a[j] > k) return false;
            }
            else {
                int q = a[j] / (r + 1);
                while (q <= 0 || a[j] / q > r) q++;
                if (q > k || a[j] / q < l) return false;
            }
        }
        return true;
        };
    int ans = INF;
    for (int i = 0; i <= N; i++) {
        int L = i, R = N;
        while (L < R) {
            int mid = (L + R) / 2;
            check(i, mid) ? R = mid : L = mid + 1;
        }
        if (check(i, R)) ans = min(ans, L - i);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int N = *max_element(a.begin(), a.end());
    auto check = [&](int l, int r) {
        //cerr << l << " -> " << r << endl;
        for (int j = 0; j < n; j++) {
            if (a[j] < l) return false;
            if (a[j] <= r) continue;
            if (r == 0) {
                if (a[j] > k) return false;
            }
            else {
                int q = a[j] / r - 5;
                while (q <= 0 || a[j] / q > r) q++;
                if (q > k || a[j] / q < l) return false;
            }
        }
        //cerr << "Great" << endl;
        return true;
        };
    int ans = INF;
    for (int i = 0; i <= N; i++) {
        //cerr << "i = " << i << endl;
        int L = i, R = N;
        while (L < R) {
            //if (R < 10)
                //cerr << L << " | " << R << endl;
            int mid = (L + R) / 2;
            check(i, mid) ? R = mid : L = mid + 1;
        }
        //cerr << "temp " << L << " " << R << endl;
        if (check(i, R)) ans = min(ans, L - i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/