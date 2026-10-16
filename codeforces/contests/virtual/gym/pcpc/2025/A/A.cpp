#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Max nodes and log(max_nodes)
const int MAXN = 100005;
const int LOGN = 18;
const int MAX_VAL = 100005; // Cap values at N+1

// Tree adjacency list
vector<int> adj[MAXN];
int A[MAXN];

// LCA and depth data
int depth[MAXN];
int parent[MAXN][LOGN];
int tin[MAXN], tout[MAXN];
int timer;

// Persistent Segment Tree Node
struct Node {
    int sum;
    Node* left, * right;
    Node(int s = 0) : sum(s), left(nullptr), right(nullptr) {}
};

Node* T_null = new Node(); // Represents an empty tree

// Persistent Segment Tree roots for each node
Node* tree_roots[MAXN];

// Build a new tree from an old one with an update
Node* update(Node* v, int tl, int tr, int pos) {
    if (tl > tr || pos < tl || pos > tr) {
        return v;
    }

    Node* new_v = new Node();
    if (tl == tr) {
        new_v->sum = 1; // Mark presence
        return new_v;
    }

    int tm = tl + (tr - tl) / 2;

    // Default to old children
    new_v->left = v->left;
    new_v->right = v->right;

    if (pos <= tm) {
        new_v->left = update(v->left, tl, tm, pos);
    }
    else {
        new_v->right = update(v->right, tm + 1, tr, pos);
    }

    new_v->sum = new_v->left->sum + new_v->right->sum;
    return new_v;
}

// Query the sum (presence) in a range
int query(Node* v, int tl, int tr, int l, int r) {
    if (tl > tr || l > r || r < tl || l > tr) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return v->sum;
    }
    int tm = tl + (tr - tl) / 2;
    return query(v->left, tl, tm, l, min(r, tm)) +
        query(v->right, tm + 1, tr, max(l, tm + 1), r);
}

// DFS for LCA and Persistent Segment Tree
void dfs_lca_pst(int u, int p, Node* p_tree) {
    tin[u] = ++timer;
    depth[u] = (p == 0) ? 0 : depth[p] + 1;
    parent[u][0] = p;

    // Build binary lifting table
    for (int i = 1; i < LOGN; ++i) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }

    // Build persistent segment tree
    tree_roots[u] = update(p_tree, 1, MAX_VAL, A[u]);

    for (int v : adj[u]) {
        if (v != p) {
            dfs_lca_pst(v, u, tree_roots[u]);
        }
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (!is_ancestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

// The query "walk"
int find_first_fail(Node* u, Node* v, Node* pl, int tl, int tr) {
    // 1. Failure check: (not in u AND not in v)
    if (u->sum == 0 && v->sum == 0) {
        return tl; // Smallest value in this range
    }

    // 2. Failure check: (in pl)
    // Check if the two ranges [tl,tr] are different
    // We can't just check sum, we must go to leaf

    if (tl == tr) {
        bool in_uv = (u->sum > 0) || (v->sum > 0);
        bool in_pl = (pl->sum > 0);

        // Fail if (not in uv) OR (in pl)
        if (!in_uv || in_pl) {
            return tl;
        }
        else {
            return -1; // This k is fine
        }
    }

    int tm = tl + (tr - tl) / 2;

    // Recurse left
    int left_fail = find_first_fail(u->left, v->left, pl->left, tl, tm);
    if (left_fail != -1) {
        return left_fail;
    }

    // Recurse right
    return find_first_fail(u->right, v->right, pl->right, tm + 1, tr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        // Cap the values
        if (A[i] > MAX_VAL) {
            A[i] = MAX_VAL;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize the empty persistent tree
    T_null->left = T_null->right = T_null;

    // Precomputation
    timer = 0;
    dfs_lca_pst(1, 0, T_null);

    // Answer queries
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;

        int l = lca(u, v);
        int pl_node = parent[l][0];

        Node* T_u = tree_roots[u];
        Node* T_v = tree_roots[v];
        Node* T_pl = (pl_node == 0) ? T_null : tree_roots[pl_node];

        int x = find_first_fail(T_u, T_v, T_pl, 1, MAX_VAL);

        if (x == -1) {
            // This should only happen if all 1..MAX_VAL are present
            cout << MAX_VAL << "\n";
        }
        else {
            cout << x - 1 << "\n";
        }
    }

    return 0;
}