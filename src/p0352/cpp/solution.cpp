/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        st2intervals.clear();
        ed2intervals.clear();
    }
    
    void addNum(int val) {
        auto nxit = ed2intervals.lower_bound(val);
        if (nxit != ed2intervals.end() && nxit->second.start <= val) {
            return;
        }
        auto stit = st2intervals.find(val + 1);
        auto edit = ed2intervals.find(val - 1);
        if (stit == st2intervals.end() && edit == ed2intervals.end()) {
            st2intervals[val] = ed2intervals[val] = Interval(val, val);
        } else
        if (stit != st2intervals.end() && edit != ed2intervals.end()) {
            st2intervals[edit->second.start].end = stit->second.end;
            ed2intervals[stit->second.end].start = edit->second.start;
            st2intervals.erase(val + 1); ed2intervals.erase(val - 1);
        } else
        if (stit == st2intervals.end() && edit != ed2intervals.end()) {
            st2intervals[edit->second.start].end = val;
            ed2intervals[val] = ed2intervals[val - 1];
            ed2intervals[val].end = val;
            ed2intervals.erase(val - 1);
        } else
        if (stit != st2intervals.end() && edit == ed2intervals.end()) {
            ed2intervals[stit->second.end].start = val;
            st2intervals[val] = st2intervals[val + 1];
            st2intervals[val].start = val;
            st2intervals.erase(val + 1);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> summary;
        for (auto &fs : st2intervals) {
            summary.push_back(fs.second);
        }
        return summary;
    }
private:
    map<int, Interval> st2intervals;
    map<int, Interval> ed2intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
