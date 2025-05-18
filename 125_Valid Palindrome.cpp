class Solution {
public:
    bool isPalindrome(string s) {
        string first_half = "";
        string second_half = "";
        int left = 0;
        int right = s.size()-1;
        char left_char = s[left];
        char right_char = s[right];

        while(left < right){
            while(!isalnum(s[left]) && left < right){ //until find valid char
                left++;
            }
            if (s[left] >= 'a'){
                s[left] = s[left]  -32;
            }
            left_char = s[left];

            while(!isalnum(s[right]) && left < right){ //until find valid char
                right--;
            }
            if(s[right] >= 'a'){
                s[right] = s[right] -32;
            }
            right_char = s[right];

            if(left_char != right_char){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};