class MedianFinder {
private:
    typedef priority_queue<int, vector<int>, less<int>> SmallerHalf;
    typedef priority_queue<int, vector<int>, greater<int>> BiggerHalf;
    SmallerHalf smaller; BiggerHalf bigger;
    
    void adjust() {
        while (smaller.size() < bigger.size()) {
            smaller.push(bigger.top()); bigger.pop();
        }
        while (smaller.size() > bigger.size() + 1) {
            bigger.push(smaller.top()); smaller.pop();
        }
    }
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (smaller.empty() || num <= smaller.top()) {
            smaller.push(num);
        } else {
            bigger.push(num);
        }
        adjust();
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smaller.size() == bigger.size()) {
            return (smaller.top() + bigger.top()) / 2.0;
        } else {
            return double(smaller.top());
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
