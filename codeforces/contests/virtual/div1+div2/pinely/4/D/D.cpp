#include<bits/stdc++.h>
using namespace std;

const int N = 3e5;
const int M = 5;
const int K = 1000;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i < M; i++) s.insert(i);
    vector<set<int>> a(n + 1, s);
    set<int> all;
    for (int i = 1; i <= n; i++) all.insert(i);
    queue<int> q;
    vector<int> ans(n + 1);
    while (!all.empty()) {
        if (q.empty()) {
            q.push(*all.begin());
        }
        int r = q.front();
        q.pop();
        all.erase(r);
        int id = *a[r].begin();
        cerr << "r = " << r << endl;
        cerr << "id = " << id << endl;
        for (auto& c : all) {
            cerr << r << " -> " << c << endl;
            if (prime[r ^ c]) {
                a[c].erase(id);
                if (a[c].size() == 1) q.push(c);
            }
        }
        ans[r] = id;
        cerr << "end" << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prime[(i ^ j)] && ans[i] == ans[j]) {
                cerr << i << "-> " << j << " " << ans[i] << endl;
                assert(false);
            }
        }
    }
    //cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}