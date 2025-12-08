#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{

    vector<int> ans;
    int first = -1;
    int last = -1;

  

    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            e = mid - 1;
        }
        else if (target > nums[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            l = mid + 1;
        }
        else if (target > nums[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    ans.push_back(first);
    ans.push_back(last);
    return ans;
}
