class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        return searchMatrixBinary(matrix, target, 0, row*col-1);
    }


    bool searchMatrixBinary(vector<vector<int>>& matrix, const int& target, int left, int right){
        if (left > right) { return false; }
        int row = matrix.size();
        int col = matrix[0].size();
        int mid = (right + left)/2;

        if (target < matrix[mid/col][mid%col]){
            return searchMatrixBinary(matrix, target, left, mid-1);
        }
        if (target > matrix[mid/col][mid%col]){
            return searchMatrixBinary(matrix, target, mid+1, right);
        }
        return true;
    }
};
