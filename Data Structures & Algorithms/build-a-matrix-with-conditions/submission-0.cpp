class Solution {
public:
    vector<int> toposort(int k,vector<vector<int>>& edges)
    {
        vector<int> order;
        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=1;i<=k;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(order.size()!=k)
        return {};
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> roworder=toposort(k,rowConditions);
        if(roworder.size()!=k)
        return {};
        vector<int> colorder=toposort(k,colConditions);
        if(colorder.size()!=k)
        return {};
        vector<int> colind(k+1);
        for(int i=0;i<k;i++)
        {
            colind[colorder[i]]=i;
        }
        vector<vector<int>> res(k,vector<int>(k));
        for(int i=0;i<k;i++)
        {
            int val=roworder[i];
            res[i][colind[val]]=val;
        }
        return res;
    }
};