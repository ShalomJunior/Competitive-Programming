#include <bits/stdc++.h>
using namespace std;

const int N = 25;
vector<int> m(N + 1);
struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;
        int pattern_end_count;
        Node() : link{}, next{}, pattern_end_count(0) {}
    };

    std::vector<Node> t;

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
        t[p].pattern_end_count++;
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
                    t[t[x].next[i]].pattern_end_count += t[t[t[x].next[i]].link].pattern_end_count;
                    q.push(t[x].next[i]);
                }
            }
        }
    }

    long long countMatches(const std::string& text, char offset = 'a') {
        long long total_matches = 0;
        int p = 1;
        for (char c : text) {
            int x = c - offset;
            p = t[p].next[x];
            total_matches += t[p].pattern_end_count;
        }
        return total_matches;
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
    vector<string> a;
    vector<string> d;
    vector<AhoCorasick> A(N + 1);
    vector<AhoCorasick> D(N + 1);
    int q;
    cin >> q;
    while (q--) {
        int t;
        string s;
        cin >> t >> s;
        if (t == 1) {
            a.push_back(s);
            int z = a.size();
            for (int j = N; j >= 0; j--) {
                int f = z & m[j];
                int g = (z - 1) & m[j];
                if (f && !g) {
                    for (int k = 0; k < m[j]; k++) {
                        A[j].add(a[z - 1 - k]);
                    }
                    A[j].work();
                }
                else if (!f && g) {
                    A[j] = AhoCorasick();
                }
                else {}
            }
        }
        else if (t == 2) {
            d.push_back(s);
            int z = d.size();
            for (int j = N; j >= 0; j--) {
                int f = z & m[j];
                int g = (z - 1) & m[j];
                if (f && !g) {
                    for (int k = 0; k < m[j]; k++) {
                        D[j].add(d[z - 1 - k]);
                    }
                    D[j].work();
                }
                else if (!f && g) {
                    D[j] = AhoCorasick();
                }
                else {}
            }
        }
        else if (t == 3) {
            long long ans = 0;
            for (int j = 0; j <= N; j++) {
                if (A[j].size() > 2) {
                    ans += A[j].countMatches(s);
                }
                if (D[j].size() > 2) {
                    ans -= D[j].countMatches(s);
                }
            }
            cout << ans << endl;
        }
        else {
            assert(false);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m[0] = 1;
    for (int i = 1; i <= N; i++) m[i] = m[i - 1] * 2;
    solve();
}
