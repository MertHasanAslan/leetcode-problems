class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = INT_MIN;
        for (int i = 0; i < heights.size() - 1; i++){
            int width = 1;
            for (int j = i + 1; j < heights.size(); j++){
                width = j - i;
                int dummy_max = min(heights[i], heights[j]) * width;
                if (dummy_max > max){
                    max = dummy_max;
                }
            }
        }

        return max;
    }
};
