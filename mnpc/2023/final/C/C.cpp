#include <bits/stdc++.h>
# define M_PI 3.14159265358979323846
using namespace std;

typedef complex<double> cd;
vector<cd> fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1)
        return vector<cd>(1, a[0]);

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }
    vector<cd> y0 = fft(a0, invert);
    vector<cd> y1 = fft(a1, invert);

    double ang = 2 * M_PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int k = 0; k < n / 2; ++k) {
        a[k] = y0[k] + w * y1[k];
        a[k + n / 2] = y0[k] - w * y1[k];
        if (invert) {
            a[k] /= cd(2);
            a[k + n / 2] /= cd(2);
        }
        w *= wn;
    }
    return a;
}

vector<double> multiply_polynomials(vector<double>& a, vector<double>& b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);

    fa = fft(fa, false);
    fb = fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fa = fft(fa, true);

    vector<double> result(n);
    for (int i = 0; i < n; ++i) result[i] = fa[i].real();
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<double> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    auto ans = multiply_polynomials(a, b);
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        printf("%.6f\n", ans[k]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}