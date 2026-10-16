#include<bits/stdc++.h>
using namespace std;

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
        for (auto& c : t[u].children) {
            dfs(c);
            t[u].tout = max(t[u].tout, t[c].tout);
        }
        t[u].tout = max(t[u].tout, t[u].tin);
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
    int idx;
    int k;
    int b;
    int j;
    bool operator<(const Query& other) const {
        return idx < other.idx;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    AhoCorasick ac;
    vector<int> end(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        end[i] = ac.add(s[i]);
    }
    ac.work();
    ac.build();
    vector<Query> Q;
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--, k--;
        if (l > 0) Q.push_back({ l - 1 , k, -1, i });
        Q.push_back({ r , k, 1, i });
    }
    sort(Q.begin(), Q.end());
    fenwick<int> fen(ac.size());
    vector<long long> ans(q);
    for (int i = 0, j = 0; i < n; i++) {
        int p = 1;
        for (auto c : s[i]) {
            p = ac.next(p, c);
            fen.add(ac.t[p].tin, 1);
        }
        while (j < Q.size() && Q[j].idx == i) {
            auto [idx, k, b, j_idx] = Q[j];
            int l = ac.t[end[k]].tin;
            int r = ac.t[end[k]].tout;
            ans[j_idx] += b * fen.rangeQuery(l, r);
            j++;
        }
    }
    for (auto& c : ans) cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}