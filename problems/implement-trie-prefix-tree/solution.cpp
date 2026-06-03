// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    bool can_end;
    unordered_map<char, Trie*> children;

    Trie() {
        can_end = false;
    }

    void insert(string word) {
        Trie* curr = this;
        for (const char& c: word) {
            if (curr->children[c] == nullptr)
                curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->can_end = true;
    }

    bool search(string word) {
        Trie* const curr = this;
        for (const char& c: word) {
            curr = curr->children[c];
            if (curr == nullptr)
                return false;
        }
        return curr->can_end;
    }

    bool startsWith(string prefix) {
        Trie* const curr = this;
        for (const char& c: prefix) {
            curr = curr->children[c];
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
