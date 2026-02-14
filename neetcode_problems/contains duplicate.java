class Solution {
    public boolean hasDuplicate(int[] nums) {
        Map<Integer, Boolean> m = new HashMap<>();

        for (int i = 0; i < nums.length; i++){
            if (m.containsKey(nums[i])) { return true; }
            m.put(nums[i], true);
        }
        return false;
    }
}