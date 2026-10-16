#include <bits/stdc++.h>
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

void solve() {
    int q, n;
    cin >> q >> n;
    AhoCorasick ac;
    string ts;
    vector<int> end(n);
    for (int i = 0; i < n; i++) {
        cin >> ts;
        end[i] = ac.add(ts);
    }
    ac.work();
    ac.build();
    int z = ac.size();
    fenwick<int> fen(2 * z);
    for (int i = 0; i < n; i++) {
        fen.add(ac.t[end[i]].tin, 1);
        fen.add(ac.t[end[i]].tout, -1);
    }
    vector<bool> in(n, true);
    while (q--) {
        string t;
        cin >> t;
        if (t[0] == '+') {
            int j = stoi(t.substr(1)) - 1;
            if (!in[j]) {
                fen.add(ac.t[end[j]].tin, 1);
                fen.add(ac.t[end[j]].tout, -1);
                in[j] = true;
            }
        }
        else if (t[0] == '-') {
            int j = stoi(t.substr(1)) - 1;
            if (in[j]) {
                fen.add(ac.t[end[j]].tin, -1);
                fen.add(ac.t[end[j]].tout, 1);
                in[j] = false;
            }
        }
        else if (t[0] == '?') {
            t = t.substr(1);
            int p = 1;
            long long ans = 0;
            for (auto& c : t) {
                p = ac.next(p, c);
                ans += fen.query(ac.t[p].tin);
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
