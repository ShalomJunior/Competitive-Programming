#include <bits/stdc++.h>
#define db double 
using namespace std;

const db e = 1e-9;

bool comp(db a, db b) {
    return abs(a - b) < e;
}

bool solve(vector<int>& v, int k, db mean) {
    int n = v.size();
    vector <int> idx(n);
    fill(idx.end() - k, idx.end(), 1);

    do {
        int t = 0;
        for (int i = 0;i < n; i++) {
            if (idx[i])t += v[i];
        }

        db ths = (db)t / (db)k;
        if (comp(ths, mean)) return true;

        //if (ths < mean) break;

    } while (next_permutation(idx.begin(), idx.end()));
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if (n < 2) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> v(n);
    for (auto& c : v) cin >> c;
    sort(v.begin(), v.end());
    int num = accumulate(v.begin(), v.end(), 0), den = n;
    int gd = gcd(num, den);
    num /= gd; den /= gd;
    db mean = ((db)num) / (db)den;
    int nb = n / 2 + (n & 1);
    for (int i = den; i <= nb; i += den) {
        bool b = solve(v, i, mean);
        if (b) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}