/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>& grid,int n,int r,int c)
    {
        if(n==1)
        {
            return new Node(grid[r][c]==1,true);
        }
        int m=n/2;
        Node* tl=solve(grid,m,r,c);
        Node* tr=solve(grid,m,r,c+m);
        Node* bl=solve(grid,m,r+m,c);
        Node* br=solve(grid,m,r+m,c+m);
        if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val==tr->val && tr->val==bl->val && bl->val==br->val)
        {
            return new Node(tl->val,true);
        }
        return new Node(true,false,tl,tr,bl,br);
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,grid.size(),0,0);
    }
};