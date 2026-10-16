#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 26;
struct SuffixArray {
    int n;
    std::vector<int> sa, rk, lc, pref;
    SuffixArray(const std::string& s) {
        n = s.length();
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
        pref.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int a, int b) {return s[a] < s[b];});
        rk[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        int k = 1;
        std::vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; ++i)
                tmp.push_back(n - k + i);
            for (auto i : sa)
                if (i >= k)
                    tmp.push_back(i - k);
            std::fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i)
                ++cnt[rk[i]];
            for (int i = 1; i < n; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            std::swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (rk[i] == 0) {
                j = 0;
            }
            else {
                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )
                    ++j;
                lc[rk[i] - 1] = j;
            }
        }
        pref[0] = n - sa[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (n - sa[i]);
        }
    }

    int compare(const std::string& S, int sa_idx, const std::string& P) {
        int suffix_start = sa[sa_idx];
        int m = P.length();
        for (int i = 0; i < m; ++i) {
            if (suffix_start + i >= n) return -1;
            if (S[suffix_start + i] < P[i]) return -1;
            if (S[suffix_start + i] > P[i]) return 1;
        }
        return 0;
    }

    int count(const std::string& S, const std::string& P, int& z) {
        if (P.empty() || (int)P.length() > n) return {};
        int m = P.length();
        int L = -1, R = -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmp = compare(S, mid, P);
            if (cmp >= 0) {
                L = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if (L == -1 || compare(S, L, P) != 0) {
            return {};
        }
        low = L;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmp = compare(S, mid, P);
            if (cmp <= 0) {
                R = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (L != -1 && R != -1) {
            z = R - L + 1;
            return pref[R] - (L ? pref[L - 1] : 0) - (m - 1) * (R - L + 1);
        }
        return 0;
    }
    int extend(const std::string S, int len, char c, int& L, int& R) {
        while (L <= R) {
            if (sa[L] + len >= n || S[sa[L] + len] < c) {
                L++;
            }
            else {
                break;
            }
        }
        while (L <= R) {
            if (sa[R] + len >= n || S[sa[R] + len] > c) {
                R--;
            }
            else {
                break;
            }
        }
        return pref[R] - (L ? pref[L - 1] : 0) - (len) * (R - L + 1);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    if (n * (n + 1) / 2 < k) {
        cout << "No such line." << endl;
        return;
    }
    SuffixArray sa(s);
    string ans;
    int z = 0;
    int L = 0, R = n - 1;
    while (z < k) {
        for (char c = 'a'; c <= 'z'; c++) {
            sa.extend(s, ans.length(), c, L, R);
            string t = ans + c;
            int add = 0;
            int cnt = sa.count(s, t, add);
            if (z + cnt >= k) {
                ans += c;
                z += add;
                break;
            }
            else {
                z += cnt;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}