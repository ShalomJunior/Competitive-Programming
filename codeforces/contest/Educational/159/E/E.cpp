#include <bits/stdc++.h>
using namespace std;

const int N = 26;
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int prefCount;
    int prefLenSum;
    int wordCount;
    TrieNode() : isEndOfWord(false), prefCount(0), prefLenSum(0), wordCount(0) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->prefCount++;
            curr->prefLenSum += word.size();
        }
        curr->isEndOfWord = true;
        curr->wordCount++;
    }
    pair<vector<int>, vector<int>> countStartWith(const string& prefix) {
        int n = prefix.length();
        vector<int> cnt(n + 1), sum(n + 1);
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            char c = prefix[i];
            if (!curr->children.count(c)) {
                cnt.push_back(0);
                return { cnt, sum };
            }
            curr = curr->children[c];
            cnt[i + 1] = curr->prefCount;
            sum[i + 1] = curr->prefLenSum;
        }
        return { cnt, sum };
    }
};

void solve() {
    int n; cin >> n;
    int tot = 0;
    Trie trie;
    vector<string> a(n);
    for (auto& c : a) {
        cin >> c;
        trie.insert(c);
        tot += c.length();
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        string t = a[i];
        int m = t.size();
        reverse(t.begin(), t.end());
        auto [cnt, sum] = trie.countStartWith(t);
        for (int len = m; len > 0; len--) {
            int k = cnt[len] - (len == m ? 0 : cnt[len + 1]);
            ans += (sum[len] - (len == m ? 0 : sum[len + 1])) - 1LL * k * len + 1LL * k * (m - len);
        }
        int x = n - cnt[1];
        int y = tot - sum[1];
        ans += 1LL * x * m + y;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}