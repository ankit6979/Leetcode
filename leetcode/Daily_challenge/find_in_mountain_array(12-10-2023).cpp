/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int bsearch(int low, int high, int n, MountainArray &mountainArr)
    {
        int mid, mid_val, left_val, right_val;
        while (low <= high)
        {
            mid = (low + high) / 2;
            mid_val = mountainArr.get(mid);
            if (mid != 0)
            {
                left_val = mountainArr.get(mid - 1);
            }
            if (mid != n)
            {
                right_val = mountainArr.get(mid + 1);
            }
            if ((mid == 0 || left_val <= mid_val) && (mid == n || mid_val >= right_val))
            {
                return mid;
            }
            if (mid > 0 && left_val > mid_val)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return mid;
    }
    int lbsearch(int low, int high, int target, MountainArray &mountainArr)
    {
        int pos = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
                // pos = mid;
                // high = mid-1;
            }
            else if (mountainArr.get(mid) > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return pos;
    }
    int rbsearch(int low, int high, int target, MountainArray &mountainArr)
    {
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int peak_idx, pos, len = mountainArr.length() - 1;
        peak_idx = bsearch(0, len, len, mountainArr);
        pos = lbsearch(0, peak_idx, target, mountainArr);
        if (pos != -1)
        {
            return pos;
        }
        else
        {
            return rbsearch(peak_idx + 1, len, target, mountainArr);
        }
        return pos;
    }
};