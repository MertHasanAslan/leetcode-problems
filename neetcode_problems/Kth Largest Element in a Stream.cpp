class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++){
            if (minheap.size() < k){
                minheap.push(nums[i]);
            }
            else{
                if (minheap.top() < nums[i]){
                    minheap.pop();
                    minheap.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if (minheap.size() < k){
            minheap.push(val);
        }
        else{
            if (minheap.top()< val){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};
