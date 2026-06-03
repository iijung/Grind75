// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    bool can_end;
    Trie* children[26];

    Trie() {
        can_end = false;
        for (auto& child: children)
            child = nullptr;
    }

    void insert(string word) {
        Trie* curr = this;
        for (const char& c: word) {
            const size_t idx = c - 'a';
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new Trie();
            curr = curr->children[idx];
        }
        curr->can_end = true;
    }

    bool search(string word) {
        Trie* curr = this;
        for (const char& c: word) {
            const size_t idx = c - 'a';
            curr = curr->children[idx];
            if (curr == nullptr)
                return false;
        }
        return curr->can_end;
    }

    bool startsWith(string prefix) {
        Trie* curr = this;
        for (const char& c: prefix) {
            const size_t idx = c - 'a';
            curr = curr->children[idx];
            if (curr == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
