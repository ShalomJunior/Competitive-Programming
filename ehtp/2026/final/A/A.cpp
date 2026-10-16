#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 9e18;
template<class T>
struct Frac {
    T num;
    T den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const {
        return 1. * num / den;
    }
    Frac& operator+=(const Frac& rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac& operator-=(const Frac& rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac& operator*=(const Frac& rhs) {
        assert(abs(num) <= (INF / abs(rhs.num)) && abs(den) <= (INF / abs(rhs.den)));
        num *= rhs.num;
        den *= rhs.den;
        T g = __gcd(num, den);
        num /= g;
        den /= g;
        return *this;
    }
    Frac& operator/=(const Frac& rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac& rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac& rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac& rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac& rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac& a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
    friend std::ostream& operator<<(std::ostream& os, Frac x) {
        T g = std::gcd(x.num, x.den);
        return os << x.num / g << "/" << x.den / g;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> t(n);
    for (auto& c : t) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool jam = false;
    vector<int> id(n, -1);
    vector<Frac<int>> w(n);
    function<void(int)> dfs = [&](int u) {
        for (auto& v : adj[u]) {
            if (id[v] == -1) {
                id[v] = id[u] ^ 1;
                w[v] = -w[u] * Frac<int>(t[u], t[v]);
                dfs(v);
            }
            else if (id[v] == id[u]) {
                jam = true;
            }
        }
        };
    id[0] = 0;
    w[0] = Frac<int>(1, 1);
    dfs(0);
    if (jam) {
        cout << "JAM\n";
        return;
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << w[u] / w[v] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}