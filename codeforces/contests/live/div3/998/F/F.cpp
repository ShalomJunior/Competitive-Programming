#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

void dec(int n, map<int, int>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div[n]++;
            return;
        }
        while (n % primes[i] == 0) {
            div[primes[i]]++;
            n /= primes[i];
        }
        i++;
    }
    if (n > 1) div[n]++;
}

const int MOD = 998244353;
const double PI = acos(-1);

// FFT Complex Number
struct Complex {
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& o) const { return { real + o.real, imag + o.imag }; }
    Complex operator-(const Complex& o) const { return { real - o.real, imag - o.imag }; }
    Complex operator*(const Complex& o) const { return { real * o.real - imag * o.imag, real * o.imag + imag * o.real }; }
};
int modular_inverse(int a, int p) {
    int result = 1, power = p - 2;
    while (power) {
        if (power & 1) result = result * a % p;
        a = a * a % p;
        power >>= 1;
    }
    return result;
}

// FFT Algorithm
void fft(vector<Complex>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        Complex wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert) {
        for (auto& x : a) {
            x.real /= n;
            x.imag /= n;
        }
    }
}

// Polynomial Multiplication using FFT
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    vector<Complex> fa(n), fb(n);
    for (size_t i = 0; i < a.size(); i++) fa[i] = Complex(a[i], 0);
    for (size_t i = 0; i < b.size(); i++) fb[i] = Complex(b[i], 0);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = (int)round(fa[i].real) % MOD;
    return result;
}

// Compute (1 / (1 - x)^(alpha + 1)) as a polynomial
vector<int> generate_series(int alpha, int n) {
    vector<int> series(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        series[i] = series[i - 1] * (alpha + i) % MOD;
        series[i] = series[i] * modular_inverse(i, MOD) % MOD;
    }
    return series;
}

// Modular Inverse using Fermat's Little Theorem


// Compute the sum S using FFT
int compute_sum(int n, const vector<int>& alphas) {
    int cnt = alphas.size();
    vector<int> result = { 1 };  // Start with a neutral polynomial
    int max_deg = n;  // Limit the degree of polynomials
    for (int alpha : alphas) {
        vector<int> series = generate_series(alpha, max_deg);
        result = multiply(result, series);
        result.resize(max_deg + 1);  // Keep only relevant terms
    }
    // Sum up coefficients from 1 to n
    int total_sum = 0;
    for (int i = 1; i <= n; i++) {
        total_sum = (total_sum + result[i]) % MOD;
    }
    return total_sum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int x = 1; x <= k; x++) {
        map<int, int> divs;
        dec(x, divs);
        vector<int> alpha;
        for (auto& [_, v] : divs) alpha.push_back(v);
        cout << compute_sum(n, alpha) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
