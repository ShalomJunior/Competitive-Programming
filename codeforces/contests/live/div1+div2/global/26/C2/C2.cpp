#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

    friend const Type& abs(const Modular& x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename V, typename U>
    friend V& operator>>(V& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
    return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

const int M = 10;

#define int long long
int brute(vector<int> a) {
    cerr << "in" << endl;
    int n = a.size() - 1;
    map<int, int> cnt;
    int mx = 0;
    for (int i = 0; i < (1 << n); i++) {
        int val = 0;
        for (int j = 0; j < n; j++) {
            val += a[j + 1];
            if (i & (1 << j)) val = abs(val);
        }
        cnt[val]++;
        mx = max(mx, val);
    }
    cerr << "out" << endl;
    return cnt[mx];

}
void solve() {
    //int n;
    //cin >> n;
    int n = rng() % M;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = rng() % M;
        a[i] -= M / 2;
        //cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        cnt[i] = cnt[i - 1] + (pref[i] >= 0);
    }
    for (auto& c : a) cerr << c << " ";
    cerr << endl;
    int mx = 0;
    map<int, vector<int>> id;
    for (int i = 1; i <= n; i++) {
        int curr = abs(pref[i]) + pref[n] - pref[i];
        id[curr].push_back(i);
        mx = max(mx, curr);
    }
    auto idx = id[mx];
    int m = idx.size();
    if (m == n) {
        for (auto& j : idx)  assert(pref[j] >= 0);
        cout << power(Mint(2), n) << endl;
        return;
    }
    Mint ans = 0;
    for (auto& j : idx) {
        int l = cnt[j - 1];
        int r = n - j;
        ans += power(Mint(2), l) * power(Mint(2), r);
    }
    Mint res = Mint(brute(a));
    cout << ans << endl;
    cerr << res << endl;
    assert(ans == res);
}


/*
Killing test case
2
-1 0
*/

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)solve();
}


/*

void solve() {
#define int long long
    cerr << endl;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        cnt[i] = cnt[i - 1] + (pref[i] >= 0);
    }
    int mx = 0;
    map<int, vector<int>> id;
    for (int i = 1; i <= n; i++) {
        cerr << "pre " << pref[i] << endl;
        int curr = abs(pref[i]) + pref[n] - pref[i];
        cerr << "curr " << curr << endl;
        id[curr].push_back(i);
        mx = max(mx, curr);
    }
    auto idx = id[mx];
    int m = idx.size();
    cerr << "m = " << m << endl;
    if (m == n) {
        cout << power(Mint(2), n) << endl;
        return;
    }
    for (auto& c : idx) cerr << c << "-> ";
    cerr << endl;
    Mint ans = 0;
    for (auto& j : idx) {
        int l = cnt[j - 1];
        int r = n - j;
        cerr << l << " " << r << endl;
        cerr << power(Mint(2), l) << " " << power(Mint(2), r) << endl;
        ans += power(Mint(2), l) * power(Mint(2), r);
        cerr << "ans = " << ans << endl;
    }
    cout << ans << endl;
    cout << "€" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/