#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int x, Node *n) : val(x), next(n) {}
    };
    Node dummy, *p;

public:
    MyLinkedList() : dummy(0, nullptr) {}

    int get(int idx) {
        for (p = &dummy; p->next && idx; idx--, p = p->next);
        return p->next ? p->next->val : -1;
    }

    void addAtHead(int val) {
        dummy.next = new Node(val, dummy.next);
    }

    void addAtTail(int val) {
        for (p = &dummy; p->next; p = p->next);
        p->next = new Node(val, nullptr);
    }

    void addAtIndex(int idx, int val) {
        for (p = &dummy; p->next && idx; idx--, p = p->next);
        if (p->next || !idx) {
            p->next = new Node(val, p->next);
        }
    }

    void deleteAtIndex(int idx) {
        for (p = &dummy; p->next && idx; idx--, p = p->next);
        if (p->next) {
            auto n = p->next; p->next = n->next; delete n;
        }
    }
};
