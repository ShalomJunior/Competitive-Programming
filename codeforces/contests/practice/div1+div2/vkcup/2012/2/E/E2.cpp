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
        std::map<int, int> next;
        int pattern_end_count;
        Node() : link{}, pattern_end_count(0) {}
    };

    std::vector<Node> t;

    AhoCorasick() {
        init();
    }

    void init() {
        t.assign(2, Node());
        t[0].len = -1;
    }

    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }

    int add(const std::string& a, char offset = 'a') {
        int p = 1;
        for (char ch : a) {
            int x = ch - offset;
            if (t[p].next.find(x) == t[p].next.end()) {
                int new_node_id = newNode();
                t[p].next[x] = new_node_id;
                t[new_node_id].len = t[p].len + 1;
            }
            p = t[p].next.at(x);
        }
        t[p].pattern_end_count++;
        return p;
    }

    int next(int p, int x) {
        if (p == 0) return 1;
        while (p != 1 && t[p].next.find(x) == t[p].next.end()) {
            p = t[p].link;
        }
        if (t[p].next.count(x)) {
            return t[p].next.at(x);
        }
        return 1;
    }

    int next(int p, char c, char offset = 'a') {
        return next(p, c - offset);
    }

    void work() {
        std::queue<int> q;
        for (auto const& [i, v] : t[1].next) {
            t[v].link = 1;
            q.push(v);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto const& [i, v] : t[x].next) {
                t[v].link = next(t[x].link, i);
                q.push(v);
            }
        }
    }

    int link(int p) {
        return t[p].link;
    }

    int size() {
        return t.size();
    }
};

void solve() {
    int q, n;
    if (!(cin >> q >> n)) return;

    AhoCorasick ac;
    vector<int> end_node_id(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        end_node_id[i] = ac.add(s);
    }
    ac.work();
    int z = ac.size();
    vector<vector<int>> adj(z);
    for (int i = 2; i < z; i++) {
        adj[ac.link(i)].push_back(i);
    }
    cerr << "z = " << z << endl;
    vector<int> tint(z), tout(z);
    function<void(int, int&)> dfs = [&](int u, int& t) {
        tint[u] = t++;

        for (auto& v : adj[u]) {
            dfs(v, t);
        }
        tout[u] = t++;
        };
    int tm = 1;
    dfs(1, tm);
    fenwick<long long> fen(2 * z + 5);
    vector<bool> is_active(n, true);
    for (int i = 0; i < n; i++) {
        int v = end_node_id[i];
        fen.add(tint[v], 1);
        fen.add(tout[v], -1);
    }
    while (q--) {
        string t;
        cin >> t;
        char op = t[0];
        if (op == '+' || op == '-') {
            int citizen_idx = stoi(t.substr(1)) - 1;
            int v = end_node_id[citizen_idx];
            if (op == '+') {
                if (!is_active[citizen_idx]) {
                    fen.add(tint[v], 1);
                    fen.add(tout[v], -1);
                    is_active[citizen_idx] = true;
                }
            }
            else {
                if (is_active[citizen_idx]) {
                    fen.add(tint[v], -1);
                    fen.add(tout[v], 1);
                    is_active[citizen_idx] = false;
                }
            }
        }
        else if (op == '?') {
            string text = t.substr(1);
            int p = 1;
            long long ans = 0;
            for (char c : text) {
                p = ac.next(p, c);
                ans += fen.query(tint[p]);
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}