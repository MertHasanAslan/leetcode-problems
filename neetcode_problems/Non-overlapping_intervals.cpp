class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int result = 0;
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            
            if (start < prev_end){ result++; }
            else{
                prev_end = intervals[i][1];
            }
        }
        return result;
    }
};