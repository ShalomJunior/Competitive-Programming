#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;

uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

template<typename T>
T extgcd(T a, T b, T& x, T& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    T p = b / a;
    T g = extgcd(b - p * a, a, y, x);
    x -= p * y;
    return g;
}

template<typename T>
bool diophantine(T a, T b, T c, T& x, T& y, T& g) {
    if (a == 0 && b == 0) {
        if (c == 0) {
            x = y = g = 0;
            return true;
        }
        return false;
    }
    if (a == 0) {
        if (c % b == 0) {
            x = 0;
            y = c / b;
            g = abs(b);
            return true;
        }
        return false;
    }
    if (b == 0) {
        if (c % a == 0) {
            x = c / a;
            y = 0;
            g = abs(a);
            return true;
        }
        return false;
    }
    g = extgcd(a, b, x, y);
    if (c % g != 0) {
        return false;
    }
    T dx = c / a;
    c -= dx * a;
    T dy = c / b;
    c -= dy * b;
    x = dx + (T)((__int128)x * (c / g) % b);
    y = dy + (T)((__int128)y * (c / g) % a);
    g = abs(g);
    return true;
}

void solve() {
    bool f = true;
    while (f) {
        int n = 50;
        //cin >> n;
        vector<int> a(n), t(n);
        for (int i = 0; i < n; i++) {
            t[i] = 1 + rng() % 1000;
            a[i] = rng() % 360;
            //cin >> t[i] >> a[i];
        }
        int ans = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int s = t[j] - t[i];
                int num = 360 * s;
                int den = t[i] * t[j];
                int g = abs(__gcd(num, den));
                int m = den / g;
                int A = num * m / den;
                int B = -360;
                int C = a[j] - a[i];
                int x, y, gc;
                if (diophantine(A, B, C, x, y, gc)) {
                    int L = -INF;
                    int R = INF;
                    while (L + 1 < R) {
                        int mid = (L + R) / 2;
                        if (x + mid * B / gc > 0) {
                            if (L == mid) x + R * B / gc > 0 ? L = R : R = L;
                            else
                                L = mid;
                        }
                        else {
                            R = mid - 1;
                        }
                    }
                    int X = x + (B / gc) * L;
                    int Y = (C - A * X) / B;
                    if (Y >= 0) {
                        ans = min(ans, m * X);
                    }
                }
            }
        }
        if (ans > 5e5 && ans <= 1e6) {
            cout << ans << endl;
            f = false;
        }
        cout << (ans > 1e6 ? -1 : ans) << endl;

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
