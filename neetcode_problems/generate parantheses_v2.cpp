class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> result;
        string str = "";

        backtracking(open, close, str, result, n);
        return result;
    }

    void backtracking(int open, int close, string str, vector<string>& result, int n){
        if (open == close && open == n){
            result.push_back(str);
            return;
        }

        if (open < n){
            backtracking(open+1, close, str + '(', result, n);
        }

        if (open > close){
            backtracking(open, close+1, str + ')', result, n);
        }

        return;
    }
};
