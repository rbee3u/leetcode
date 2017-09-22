#include <iostream>
#include <vector>

using namespace std;


class Trie {
public:
    struct Node {
        Node *child[2];
    };

    Trie(vector<int> &nums) : index(0) {
        cap = nums.size() * 31 + 1;
        pool = new Node[cap];
        root = alloc();
        for (auto num : nums) {
            auto curr = root;
            for (int i = 30; i >= 0; i--) {
                auto key = (num >> i) & 1;
                if (!curr->child[key]) {
                    curr->child[key] = alloc();
                }
                curr = curr->child[key];
            }
        }
    }

    int match(int num) {
        int res = 0;
        auto curr = root;
        for (int i = 30; i >= 0; i--) {
            auto key = (num >> i) & 1;
            auto another = key ^ 1;
            if (curr->child[another]) {
                res |= another << i;
                curr = curr->child[another];
            } else {
                res |= key << i;
                curr = curr->child[key];
            }
        }
        return res;
    }

    ~Trie() {
        delete[] pool;
    }

private:
    size_t cap, index;
    Node *pool, *root;

    Node *alloc() {
        if (index < cap) {
            (pool + index)->child[0] = nullptr;
            (pool + index)->child[1] = nullptr;
            return (pool + index++);
        } else {
            return nullptr;
        }
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int result = 0;
        Trie trie(nums);
        for (auto x : nums) {
            auto y = trie.match(x);
            if (result < (x ^ y)) {
                result = x ^ y;
            }
        }
        return result;
    }
};