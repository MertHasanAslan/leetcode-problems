class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = INT_MIN;
        for(int pile : piles){
            if (pile > max) { max = pile; }
        }
        int result = max;


        while(min <= max){
            int mid = (max + min) / 2;
            int total_hours = 0;
            for(int pile : piles){
                total_hours += (pile + mid - 1)/mid;
            }
            if (total_hours <= h){
                result = mid;
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
        }
        return result;
    }
};
