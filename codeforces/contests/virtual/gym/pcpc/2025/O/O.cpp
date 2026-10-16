#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAX_SAM_NODES = 2 * MAXN;
const int LOGN = 18;

// Sieve for Mobius function and divisors
int mu[MAXN];
vector<int> divisors[MAXN];

void sieve(int n) {
    fill(mu, mu + n + 1, 0);
    vector<int> primes;
    vector<bool> is_composite(n + 1, false);
    mu[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_composite[i * p] = true;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            }
            else {
                mu[i * p] = -mu[i];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }
}

// Suffix Automaton
struct SAM_Node {
    int len, link;
    unordered_map<char, int> next;
};

SAM_Node sam[MAX_SAM_NODES];
int sz, last;
vector<int> link_tree_adj[MAX_SAM_NODES];
int pos_to_node[MAXN];

void sam_init() {
    sam[0].len = 0;
    sam[0].link = -1;
    sz = 1;
    last = 0;
}

void sam_extend(char c, int pos_idx) {
    int cur = sz++;
    sam[cur].len = sam[last].len + 1;
    pos_to_node[pos_idx] = cur;

    int p = last;
    while (p != -1 && sam[p].next.find(c) == sam[p].next.end()) {
        sam[p].next[c] = cur;
        p = sam[p].link;
    }

    if (p == -1) {
        sam[cur].link = 0;
    }
    else {
        int q = sam[p].next[c];
        if (sam[q].len == sam[p].len + 1) {
            sam[cur].link = q;
        }
        else {
            int clone = sz++;
            sam[clone].len = sam[p].len + 1;
            sam[clone].next = sam[q].next;
            sam[clone].link = sam[q].link;
            while (p != -1 && sam[p].next[c] == q) {
                sam[p].next[c] = clone;
                p = sam[p].link;
            }
            sam[q].link = clone;
            sam[cur].link = clone;
        }
    }
    last = cur;
}

// Binary Lifting on Link Tree
int up[MAX_SAM_NODES][LOGN];

void build_link_tree() {
    for (int i = 1; i < sz; ++i) {
        link_tree_adj[sam[i].link].push_back(i);
        up[i][0] = sam[i].link;
    }
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i < sz; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

// DSU on Tree part
long long ans[MAX_SAM_NODES];
vector<int>* endpos_sets[MAX_SAM_NODES];
unordered_map<int, int>* counts[MAX_SAM_NODES];
bool is_initial_endpos[MAX_SAM_NODES];

void dfs_solve(int u) {
    endpos_sets[u] = new vector<int>();
    counts[u] = new unordered_map<int, int>();
    if (is_initial_endpos[u]) {
        int p = sam[u].len;
        endpos_sets[u]->push_back(p);
        for (int d : divisors[p]) {
            (*counts[u])[d] = 1;
        }
    }

    int heavy_child = -1;
    int max_size = -1;

    for (int v : link_tree_adj[u]) {
        dfs_solve(v);
        if ((int)endpos_sets[v]->size() > max_size) {
            max_size = (int)endpos_sets[v]->size();
            heavy_child = v;
        }
    }

    if (heavy_child != -1) {
        swap(ans[u], ans[heavy_child]);
        swap(endpos_sets[u], endpos_sets[heavy_child]);
        swap(counts[u], counts[heavy_child]);
    }

    for (int v : link_tree_adj[u]) {
        if (v == heavy_child) continue;

        ans[u] += ans[v];

        long long cross_term = 0;
        for (auto const& [d, count_v] : *counts[v]) {
            if (mu[d] != 0 && counts[u]->count(d)) {
                cross_term += (long long)mu[d] * (*counts[u])[d] * count_v;
            }
        }
        ans[u] -= cross_term;

        for (int p : *endpos_sets[v]) {
            endpos_sets[u]->push_back(p);
            for (int d : divisors[p]) {
                (*counts[u])[d]++;
            }
        }
        delete endpos_sets[v];
        delete counts[v];
    }
}


struct Query {
    int l, r, id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    sieve(n);

    sam_init();
    for (int i = 0; i < n; ++i) {
        sam_extend(s[i], i + 1);
    }

    for (int i = 1; i <= n; ++i) {
        is_initial_endpos[pos_to_node[i]] = true;
    }

    build_link_tree();

    int q;
    cin >> q;
    vector<Query> queries(q);
    vector<vector<int>> queries_by_node(sz);
    vector<long long> final_ans(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
        int len = queries[i].r - queries[i].l + 1;
        int curr = pos_to_node[queries[i].r];

        for (int j = LOGN - 1; j >= 0; --j) {
            if (up[curr][j] != 0 && sam[up[curr][j]].len >= len) {
                curr = up[curr][j];
            }
        }
        if (sam[curr].len >= len && sam[sam[curr].link].len < len) {
            // Already correct
        }
        else if (sam[curr].len >= len) {
            // Need to check the final step if up[curr][0] is still valid
            if (sam[up[curr][0]].len >= len) curr = up[curr][0];
        }


        queries_by_node[curr].push_back(i);
    }

    dfs_solve(0);

    for (int i = 0; i < sz; ++i) {
        for (int q_id : queries_by_node[i]) {
            final_ans[q_id] = ans[i];
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << final_ans[i] << "\n";
    }

    // Clean up memory to be proper, though not strictly necessary in competitive programming
    delete endpos_sets[0];
    delete counts[0];

    return 0;
}