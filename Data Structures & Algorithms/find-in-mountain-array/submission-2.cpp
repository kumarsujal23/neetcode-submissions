/**
 * // This is the MountainArray's API interface.
 * // You should not icachelement it, or speculate about its icachelementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    unordered_map<int,int> cache;
    int get(int index,MountainArray &mountainArr)
    {
        if(cache.find(index)==cache.end())
        {
            cache[index]=mountainArr.get(index);
        }
        return cache[index];
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=-1,peakval=0;
        int l=1,r=mountainArr.length()-2;
        while(l<=r)
        {
            int m=(l+r)/2;
            int left=get(m-1,mountainArr);
            int mid=get(m,mountainArr);
            int right=get(m+1,mountainArr);
            if(left<mid && mid<right)
            l=m+1;
            else if(left>mid && mid>right)
            r=m-1;
            else 
            {
                peak=m;
                peakval=mid;
                break;
            }
        }
        l=0;
        r=peak-1;
        if(peakval==target)
        return peak;
        while(l<=r)
        {
            int m=(l+r)/2;
            int ele=get(m,mountainArr);
            if(ele==target)
            return m;
            else if(ele>target)
            r=m-1;
            else 
            l=m+1;
        }
        l=peak+1;
        r=mountainArr.length()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            int ele=get(m,mountainArr);
            if(ele==target)
            return m;
            else if(ele>target)
            l=m+1;
            else 
            r=m-1;
        }
        return -1;
        
    }
};