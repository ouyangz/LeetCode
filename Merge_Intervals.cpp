class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), IntervalComp);
        vector<Interval> result;
        int n = intervals.size();
        if (n == 0) {
            return result;
        }
        int s = intervals[0].start;
        int e = intervals[0].end;
        for (int i = 1; i < n; ++i) {
            if (intervals[i].start <= e) {
                e = max(e, intervals[i].end);
            }
            else {
                result.push_back(Interval(s, e));
                s = intervals[i].start;
                e = intervals[i].end;
            }
        }
        result.push_back(Interval(s, e));
        return result;
    }
private:
    static bool IntervalComp(Interval a, Interval b) {
        if (a.start == b.start) {
            return (a.end < b.end);
        }
        else {
            return (a.start < b.start);
        }
    }
};