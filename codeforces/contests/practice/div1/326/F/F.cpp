#include <bits/stdc++.h>
using namespace std;

const int B = 320;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;
        std::vector<int> children;
        int tin;
        int tout;
        Node() : link{}, next{}, tin(0), tout(0) {}
    };

    std::vector<Node> t;
    int timer;
    AhoCorasick() {
        init();
    }

    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }

    int add(const std::vector<int>& a) {
        int p = 1;
        for (auto x : a) {
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        return p;
    }

    int add(const std::string& a, char offset = 'a') {
        std::vector<int> b(a.size());
        for (int i = 0; i < (int)a.size(); i++) {
            b[i] = a[i] - offset;
        }
        return add(b);
    }

    void work() {
        std::queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                }
                else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }

    void dfs(int u) {
        t[u].tin = ++timer;
        for (auto& c : t[u].children) dfs(c);
        t[u].tout = ++timer;
    }

    void build() {
        int z = t.size();
        for (int i = 2; i < z; i++) {
            t[t[i].link].children.push_back(i);
        }
        timer = 0;
        dfs(1);
    }

    int next(int p, int x) {
        return t[p].next[x];
    }

    int next(int p, char c, char offset = 'a') {
        return next(p, c - offset);
    }

    int link(int p) {
        return t[p].link;
    }

    int len(int p) {
        return t[p].len;
    }

    int size() {
        return t.size();
    }
};

struct Query {
    int l, r, idx;
    long long ans;
};

void solve() {
    int n, q;
    cin >> n >> q;
    AhoCorasick ac;
    vector<string> s(n);
    for (auto& str : s) {
        cin >> str;
        ac.add(str);
    }
    ac.work();
    ac.build();
    vector<int> end(n);
    vector<vector<int>> ends(ac.size());
    vector<vector<int>> pass(ac.size());
    for (int i = 0; i < n; i++) {
        int p = 1;
        for (auto& c : s[i]) {
            p = ac.next(p, c);
            pass[p].push_back(i);
        }
        end[i] = p;
        ends[p].push_back(i);
    }
    vector<vector<Query>> Q(n);
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--, k--;
        Q[k].push_back({ l, r, i, 0 });
    }
    function<void(int, fenwick<int>&)> dfs = [&](int r, fenwick<int>& fen) {
        for (auto& i : ends[r]) fen.add(i + 1, 1);
        for (auto& p : pass[r]) {
            if (Q[p].size() > B) continue;
            for (auto& query : Q[p]) {
                query.ans += fen.rangeQuery(query.l + 1, query.r + 1);
            }
        }
        for (auto& c : ac.t[r].children) dfs(c, fen);
        for (auto& i : ends[r]) fen.add(i + 1, -1);
        };
    fenwick<int> fen(n);
    dfs(1, fen);
    vector<long long> pref;
    function<int(int, int)> go = [&](int r, int i) {
        int cnt = 0;
        for (auto& j : pass[r]) cnt += j == i;
        for (auto& c : ac.t[r].children) cnt += go(c, i);
        for (auto& j : ends[r]) pref[j] = cnt;
        return cnt;
        };
    for (int i = 0; i < n; i++) {
        if (Q[i].size() <= B) continue;
        pref.clear();
        pref.resize(n);
        go(1, i);
        for (int j = 1; j < n; j++) pref[j] += pref[j - 1];
        for (auto& query : Q[i]) {
            query.ans = pref[query.r];
            if (query.l > 0) query.ans -= pref[query.l - 1];
        }
    }
    vector<long long> ans(q);
    for (auto& v : Q) {
        for (auto& p : v) {
            ans[p.idx] = p.ans;
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}