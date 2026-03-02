class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = (right + left)/2;

        while (left <= right){
            if (target < nums[mid]){
                right = mid-1;
                mid = (right + left)/2;
                continue;
            }
            if (target > nums[mid]){
                left = mid+1;
                mid = (right + left)/2;
                continue;
            }
            return mid;
        }

        return -1;
    }
};
