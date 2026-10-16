#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* l, * r;
    int cnt;
    Node(int val = 0) : l(nullptr), r(nullptr), cnt(val) {}
    Node(Node* _l, Node* _r) : l(_l), r(_r), cnt(0) {
        if (l) cnt += l->cnt;
        if (r) cnt += r->cnt;
    }
};

struct PersistentSegmentTree {
    vector<Node*> roots;
    int n;

    PersistentSegmentTree(int size) : n(size) {
        roots.push_back(build(0, n - 1));
    }

    Node* build(int tl, int tr) {
        if (tl == tr) return new Node();
        int tm = (tl + tr) / 2;
        return new Node(build(tl, tm), build(tm + 1, tr));
    }

    Node* update(Node* v, int tl, int tr, int pos) {
        if (tl == tr) return new Node(v->cnt + 1);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return new Node(update(v->l, tl, tm, pos), v->r);
        else
            return new Node(v->l, update(v->r, tm + 1, tr, pos));
    }

    void add_version(int pos) {
        roots.push_back(update(roots.back(), 0, n - 1, pos));
    }

    int query(Node* vr, Node* vl, int tl, int tr, int k) {
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int left_count = vr->l->cnt - vl->l->cnt;
        if (k <= left_count)
            return query(vr->l, vl->l, tl, tm, k);
        else
            return query(vr->r, vl->r, tm + 1, tr, k - left_count);
    }

    int query(int L, int R, int k) {
        return query(roots[R + 1], roots[L], 0, n - 1, k);
    }
};

struct SuffixArray {
    int n;
    std::vector<int> sa, rk, lc;
    PersistentSegmentTree pst;

    SuffixArray(const std::string& s) : n(s.length()), pst(s.length()) {
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
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

        for (int i = 0; i < n; ++i) {
            pst.add_version(sa[i]);
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

    int query(const std::string& S, const std::string& P) {
        if (P.empty() || (int)P.length() > n) return 0;
        int m = P.length();

        int L = -1, R = -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmp = compare(S, mid, P);
            if (cmp >= 0) { L = mid; high = mid - 1; }
            else { low = mid + 1; }
        }

        if (L == -1 || compare(S, L, P) != 0) return 0;

        low = L; high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmp = compare(S, mid, P);
            if (cmp <= 0) { R = mid; low = mid + 1; }
            else { high = mid - 1; }
        }

        int total_occ = R - L + 1;
        if (total_occ == 0) return 0;

        int k_low = 0;
        int k_high = total_occ / 2;
        int ans = 0;

        auto check = [&](int k) {
            if (k == 0) return true;
            int k_smallest_start = pst.query(L, R, k);
            int k_largest_start = pst.query(L, R, total_occ - k + 1);
            return k_smallest_start + m - 1 < k_largest_start;
            };

        while (k_low <= k_high) {
            int k_mid = k_low + (k_high - k_low) / 2;
            if (check(k_mid)) {
                ans = k_mid;
                k_low = k_mid + 1;
            }
            else {
                k_high = k_mid - 1;
            }
        }
        return ans;
    }
};

void solve() {
    string s;
    cin >> s;
    SuffixArray sa(s);
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        cout << sa.query(s, t) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}