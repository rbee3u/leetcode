#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node *flatten(Node *head) {
        if (!head) { return head; }
        Node dummy(0, nullptr, nullptr, nullptr), *prev = &dummy;
        stack<Node *> stk; stk.push(head);
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();
            curr->prev = prev;
            prev->next = curr;
            if (curr->next) {
                stk.push(curr->next); curr->next = nullptr;
            }
            if (curr->child) {
                stk.push(curr->child); curr->child = nullptr;
            }
            prev = curr;
        }
        head->prev = nullptr;
        return head;
    }
};