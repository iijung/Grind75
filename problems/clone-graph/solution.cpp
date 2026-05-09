// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> clone;
        queue<Node*> q;
        q.push(node);
        clone[node] = new Node(node->val);
        while (!q.empty()) {
            Node *target = q.front();
            q.pop();
            for (Node* neighbor : target->neighbors) {
                if (clone.count(neighbor) == 0) {
                    q.push(neighbor);
                    clone[neighbor] = new Node(neighbor->val);
                }
                clone[target]->neighbors.push_back(clone[neighbor]);
            }
        }
        return clone[node];
    }
};
