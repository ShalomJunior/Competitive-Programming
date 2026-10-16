#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));  // seed random generator

    int n, m;
    // If the generator is run without input, use default values.
    if (!(cin >> n >> m)) {
        n = 10;
        m = 15;
    }
    // Ensure m is at least n-1 (to guarantee connectivity)
    m = max(m, n - 1);

    vector<tuple<int, int, char>> edges;

    // Create a random spanning tree (n-1 edges)
    for (int i = 1; i < n; i++) {
        int u = i;
        int v = rand() % i; // choose a random vertex from 0 to i-1
        char c = 'a' + rand() % 26; // random character from 'a' to 'z'
        edges.push_back({ u, v, c });
    }

    int extra = m - (n - 1);
    set<pair<int, int>> used;
    for (auto& edge : edges) {
        int u, v; char c;
        tie(u, v, c) = edge;
        if (u > v) swap(u, v);
        used.insert({ u,v });
    }

    // Add extra random edges that are not already present.
    while (extra > 0) {
        int u = rand() % n;
        int v = rand() % n;
        if (u == v) continue; // skip self-loops
        if (u > v) swap(u, v);
        if (used.count({ u,v })) continue;
        char c = 'a' + rand() % 26;
        edges.push_back({ u, v, c });
        used.insert({ u,v });
        extra--;
    }

    // Shuffle edges to randomize order
    random_shuffle(edges.begin(), edges.end());

    // Output in the expected format (converting vertices to 1-indexed)
    cout << n << " " << m << "\n";
    for (auto& edge : edges) {
        int u, v; char c;
        tie(u, v, c) = edge;
        cout << u + 1 << " " << v + 1 << " " << c << "\n";
    }
    return 0;
}
