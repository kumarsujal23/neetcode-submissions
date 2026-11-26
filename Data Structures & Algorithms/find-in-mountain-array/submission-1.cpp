/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=-1,peakval=0;
        int l=1,r=mountainArr.length()-2;
        while(l<=r)
        {
            int m=(l+r)/2;
            int left=mountainArr.get(m-1);
            int mid=mountainArr.get(m);
            int right=mountainArr.get(m+1);
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
            int ele=mountainArr.get(m);
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
            int ele=mountainArr.get(m);
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