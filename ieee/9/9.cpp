#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {}
};

class Trie {
private:
    TrieNode* root;

    int countWordsWithPrefix(TrieNode* node) {
        int count = 0;
        if (node->is_end_of_word) {
            count++;
        }
        for (const auto& child : node->children) {
            count += countWordsWithPrefix(child.second);
        }
        return count;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    int searchPrefix(const std::string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return 0;  // No words with this prefix
            }
            node = node->children[c];
        }
        return countWordsWithPrefix(node);
    }

    std::vector<std::string> getWordsWithPrefix(const std::string& prefix) {
        std::vector<std::string> result;
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return result;  // No words with this prefix
            }
            node = node->children[c];
        }

        // Use depth-first search to collect all words with the given prefix
        std::string current_word = prefix;
        collectWordsWithPrefix(node, current_word, result);

        return result;
    }

    void collectWordsWithPrefix(TrieNode* node, std::string& current_word, std::vector<std::string>& result) {
        if (node->is_end_of_word) {
            result.push_back(current_word);
        }
        for (const auto& child : node->children) {
            current_word.push_back(child.first);
            collectWordsWithPrefix(child.second, current_word, result);
            current_word.pop_back();  // Backtrack to previous state
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;
    Trie pre, suf;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        pre.insert(s);
        reverse(s.begin(), s.end());
        suf.insert(s);
    }
    while (m--) {
        string s; cin >> s;
        cout << "s = " << s << endl;
        int n = s.size();
        if (n < 6) {
            cout << "none" << endl;
            continue;
        }
        long long good = 0;
        for (int i = 3; good < 2 && i <= n - 3; i++) {
            string pref = s.substr(0, i);
            string suff = s.substr(i, n - i);
            int x = pre.searchPrefix(pref);
            int y = suf.searchPrefix(suff);
            good += 1LL * x * y;
        }
        if (good > 1) cout << "ambiguous";
        else {
            for (int i = 3; good < 2 && i <= n - 3; i++) {
                string pref = s.substr(0, i);
                string suff = s.substr(i, n - i);
                int x = pre.searchPrefix(pref);
                int y = suf.searchPrefix(suff);
                if (x == y) {
                    string a = pre.getWordsWithPrefix(pref)[0];
                    string b = suf.getWordsWithPrefix(suff)[0];
                    cout << a << " " << b << endl;
                    break;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}




