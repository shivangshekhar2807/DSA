#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> arr;
    

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int val = nums[i];

        int s = i + 1;
        int e = nums.size() - 1;

        while (s < e)
        {
            if (val + nums[s] + nums[e] == 0)
            {
                vector<int> ans;
                ans.push_back(val);
                ans.push_back(nums[s]);
                ans.push_back(nums[e]);
                arr.push_back(ans);
                s++;
                e--;

                while (s < e && nums[s] == nums[s - 1])
                    s++;

                while (s < e && nums[e] == nums[e + 1])
                    e--;
            }
            else if (val + nums[s] + nums[e] > 0)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
    }
    return arr;
}


//Set

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> arr;
    set<vector<int>> st;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {

        int val = nums[i];

        int s = i + 1;
        int e = nums.size() - 1;

        while (s < e)
        {
            if (val + nums[s] + nums[e] == 0)
            {
                st.insert({val, nums[s], nums[e]});
                s++;
                e--;
            }
            else if (val + nums[s] + nums[e] > 0)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
    }
    for (auto &v : st)
    {
        arr.push_back(v);
    }

    return arr;
}