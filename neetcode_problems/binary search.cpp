class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, target, 0, nums.size()-1);
    }

    int searchHelper(vector<int>& nums, int target, int start, int end){
        if (start > end) {return -1;}
        int mid = start + ((end - start) / 2);
        if (nums[mid] == target) { return mid; }
        else if (target < (nums[mid])) {
            return searchHelper(nums, target, start, mid-1);
        }
        else {
            return searchHelper(nums, target, mid+1, end);
        }

    }

};
