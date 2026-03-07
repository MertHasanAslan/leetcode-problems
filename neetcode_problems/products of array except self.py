class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1] * len(nums)
        pre = 1
        post = 1

        for i in range(1, len(nums)):
            pre *= nums[i-1]
            result[i] *= pre 


        for i in range(len(nums)-2, -1, -1):
            post *= nums[i+1]
            result[i] *= post

        return result
        