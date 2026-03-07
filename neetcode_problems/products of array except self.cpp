class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int pre = 1;
        int post = 1;

        for (int i = 1; i < nums.size(); i++){
            pre = pre * nums[i-1];
            result[i] = result[i] * pre;
        }

        for (int i = nums.size()-2; i >= 0; i--){
            post = post * nums[i+1];
            result[i] = result[i] * post;
        }

        return result;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());
        prefix[0] = 1;
        postfix[nums.size()-1] = 1;

        int pre = 1;
        int post = 1;
        
        for (int i = 1; i < nums.size(); i++){
            pre = pre * nums[i-1];
            prefix[i] = pre;
        }

        for (int i = nums.size()-2; i >= 0; i--){
            post = post * nums[i+1];
            postfix[i] = post;
        }

        for (int i = 0; i < nums.size(); i++){
            result.push_back(prefix[i] * postfix[i]);
        }

        return result;
    }
};
