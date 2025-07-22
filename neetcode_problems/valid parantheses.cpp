class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';

        for (char i : s) {
            if (i == '(' || i == '[' || i == '{'){
                stack.push(i);
            }
            else{
                if (!stack.empty() && map[i] == stack.top()){
                    stack.pop();
                }
                else{ return false; }
            }
        }
        return stack.empty();
    }
};
