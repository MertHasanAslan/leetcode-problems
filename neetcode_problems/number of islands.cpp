class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == '1'){
                    result++;
                    bfs(i, j, grid);
                }
            }
        }
        return result;
    }

    void bfs(int row, int col, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        grid[row][col] = '0';
        q.push({row, col});

        while(q.empty() == false){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            for (int i = 0; i < 4; i++){
                int new_row = row + directions[i][0];
                int new_col = col + directions[i][1];
                if (new_row >=0 && new_row < grid.size() &&
                    new_col >=0 && new_col < grid[0].size() &&
                    grid[new_row] [new_col] == '1'
                ) 
                {
                    grid[new_row][new_col] = '0';
                    q.push({new_row, new_col});
                }
            }
        }
        return;
    }
};

