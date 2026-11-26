class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int l=0,r=heights.size()-1;
        int area=0;
        while(l<r)
        {
            area=min(heights[l],heights[r])*(r-l);
            ans=max(area,ans);
            if(heights[l]>heights[r])
            r--;
            else
            l++;
        }
        ans=max(area,ans);
        return ans;

    }
};
