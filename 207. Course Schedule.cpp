class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> result;
        queue<int> q;
        for(auto pre : prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < n; i++){
            if (indegree[i] == 0){
                q.push(i); // add all indegree 0 vertexes.
            }
        }

        while(q.empty() != true){
            int vertex = q.front();
            q.pop();
            result.push_back(vertex);
            
            for(auto neighbor: adj[vertex]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return result.size() == n;
    }
};