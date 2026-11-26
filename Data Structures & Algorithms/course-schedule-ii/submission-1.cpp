class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> indeg(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int> q;
        int i=0;
        while(i<numCourses)
        {
            if(indeg[i]==0)
            q.push(i);
            i++;
        }
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto neigh:adj[f])
            {
                indeg[neigh]--;
                if(indeg[neigh]==0)
                q.push(neigh);
            }
        }
        if(ans.size()!=numCourses)
        return {};
        else
        return ans;
    }
};
