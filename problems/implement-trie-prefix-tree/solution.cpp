// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    bool is_end;
    unordered_map<char, Trie*> children;

    Trie() {
        is_end = false;
    }

    void insert(string word) {
        if (word.empty())
            return;
        Trie* curr = this;
        for (const char& c: word) {
            if (curr->children[c] == nullptr)
                curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->is_end = true;
    }

    bool search(string word) {
        if (word.empty())
            return is_end;
        const auto& curr = children.find(word[0]);
        if (curr == children.end())
            return false;
        const auto& [_, next] = *curr;
        return next->search(word.substr(1));
    }

    bool startsWith(string prefix) {
        if (prefix.empty())
            return true;
        const auto& curr = children.find(prefix[0]);
        if (curr == children.end())
            return false;
        const auto& [_, next] = *curr;
        return next->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
