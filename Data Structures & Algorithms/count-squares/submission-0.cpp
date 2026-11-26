class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> pts;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x=point[0],y=point[1];
        int ans=0;
        for(auto it:pts[x])
        {
            int y1=it.first;
            int cntpt=it.second;
            if(y1==y)
            continue;
            int side=y1-y;
            int x2=x+side,x3=x-side;
            ans+=cntpt*pts[x2][y1]*pts[x2][y];
            ans+=cntpt*pts[x3][y1]*pts[x3][y];
        }
        return ans;
    }
};
