class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int target = 0; target < nums.size()-2; target++){
            // if duplicate, continue
            if (target > 0 && nums[target] == nums[target-1]) { continue; }

            // two pointer
            int left = target+1;
            int right = nums.size()-1;

            while (left<right){
                if (nums[target] + nums[left] + nums[right] == 0){
                    vector<int> temp{nums[target], nums[left], nums[right]};
                    result.push_back(temp);
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) { left++; } //preventing dup
                    while(left < right && nums[right] == nums[right+1]) { right--; } // preventing dup
                }
                else if (nums[target] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return result;
    }
};
