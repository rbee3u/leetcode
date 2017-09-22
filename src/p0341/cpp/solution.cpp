/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nl) {
        bstk.push(nl.begin()); estk.push(nl.end());
    }

    int next() {
        hasNext();
        return (bstk.top()++)->getInteger();
    }

    bool hasNext() {
        for (; !bstk.empty() && !estk.empty(); ) {
            auto bit = bstk.top(), eit = estk.top();
            if (bit == eit) {
                bstk.pop(); estk.pop(); continue;
            }
            if (bit->isInteger()) {
                return true;
            }
            auto tmp = bstk.top()++;
            auto bit2 = tmp->getList().begin();
            auto eit2 = tmp->getList().end();
            bstk.push(bit2); estk.push(eit2);
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> bstk, estk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
