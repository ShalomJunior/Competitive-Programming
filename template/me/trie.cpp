#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int prefCount;
    int wordCount;
    TrieNode() : isEndOfWord(false), prefCount(0), wordCount(0) {}
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
        }
        curr->isEndOfWord = true;
        curr->wordCount++;
    }
    int count(const string& word) const {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                return 0;
            }
            curr = curr->children[c];
        }
        return curr->wordCount;
    }
    vector<int> countStartWith(const string& prefix) {
        int n = prefix.length();
        vector<int> result(n + 1);
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            char c = prefix[i];
            if (!curr->children.count(c)) {
                result.push_back(0);
                return result;
            }
            curr = curr->children[c];
            result[i + 1] = curr->prefCount;
        }
        return result;
    }
};

