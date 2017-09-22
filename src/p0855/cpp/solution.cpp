#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class ExamRoom {
public:

    struct Interval {
        int n, l, r;
        Interval() : n(0), l(0), r(0) {};
        Interval(int n, int l, int r) : n(n), l(l), r(r) {}
        bool lopen() const {
            return l == -1;
        }
        bool ropen() const {
            return r ==  n;
        }
        int size() const {
            if (lopen()) return 0 + r;
            if (ropen()) return n - 1 - l;
            return (r - l) / 2;
        }
        int pivot() const {
            if (lopen()) return 0;
            if (ropen()) return n - 1;
            return (l + r) / 2;
        }
        bool operator<(const Interval &other) const {
            int diff = size() - other.size();
            return diff ? diff > 0 : l < other.l;
        }
    };

    ExamRoom(int n) : n(n) {
        Interval node(n, -1, n);
        tree.insert(node);
        lmap[node.l] = node;
        rmap[node.r] = node;
    }

    int seat() {
        auto it = tree.begin();
        auto pv = it->pivot();
        Interval lint(n, it->l, pv - 1);
        Interval rint(n, pv + 1, it->r);
        lmap.erase(it->l);
        rmap.erase(it->r);
        tree.erase(it);
        if (lint.l <= lint.r) {
            tree.insert(lint);
            lmap[lint.l] = lint;
            rmap[lint.r] = lint;
        }
        if (rint.l <= rint.r) {
            tree.insert(rint);
            lmap[rint.l] = rint;
            rmap[rint.r] = rint;
        }
//        cout << "=======seat()=======" << endl;
//        cout << "tree: " << endl;
//        for (auto &node : tree) {
//            cout << "[" << node.l << ", " << node.r << "]" << endl;
//        }
//        cout << "lmap: " << endl;
//        for (auto &pair : lmap) {
//            cout << pair.first << ": ";
//            cout << "[" << pair.second.l << ", " << pair.second.r << "]" << endl;
//        }
//        cout << "rmap: " << endl;
//        for (auto &pair : rmap) {
//            cout << pair.first << ": ";
//            cout << "[" << pair.second.l << ", " << pair.second.r << "]" << endl;
//        }
        return pv;
    }

    void leave(int pv) {
        Interval lint(n, pv, pv);
        if (rmap.count(pv - 1)) {
            lint = rmap[pv - 1];
            tree.erase(lint);
            lmap.erase(lint.l);
            rmap.erase(lint.r);
        }
        Interval rint(n, pv, pv);
        if (lmap.count(pv + 1)) {
            rint = lmap[pv + 1];
            tree.erase(rint);
            lmap.erase(rint.l);
            rmap.erase(rint.r);
        }
        Interval node(n, lint.l, rint.r);
        tree.insert(node);
        lmap[node.l] = node;
        rmap[node.r] = node;
//        cout << "=======leave()=======" << endl;
//        cout << "tree: " << endl;
//        for (auto &node : tree) {
//            cout << "[" << node.l << ", " << node.r << "]" << endl;
//        }
//        cout << "lmap: " << endl;
//        for (auto &pair : lmap) {
//            cout << pair.first << ": ";
//            cout << "[" << pair.second.l << ", " << pair.second.r << "]" << endl;
//        }
//        cout << "rmap: " << endl;
//        for (auto &pair : rmap) {
//            cout << pair.first << ": ";
//            cout << "[" << pair.second.l << ", " << pair.second.r << "]" << endl;
//        }
    }

private:
    int n;
    unordered_map<int, Interval> lmap, rmap;
    set<Interval> tree;
};

int main() {
    ExamRoom er(4);
    cout << er.seat() << endl;
    cout << er.seat() << endl;
    cout << er.seat() << endl;
    cout << er.seat() << endl;
    er.leave(1);
    er.leave(3);
    cout << er.seat() << endl;
    return 0;
}