class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = INT_MIN;

        int left = 0;
        int right = heights.size() - 1;

        while(left < right){
            int width = right - left;
            int dummy_max = min(heights[left], heights[right]) * width;
            if (dummy_max > max) { max = dummy_max; }

            if (heights[left] <= heights[right]) { left++; }
            else{ right--; }
        }
        return max;
    }
};
