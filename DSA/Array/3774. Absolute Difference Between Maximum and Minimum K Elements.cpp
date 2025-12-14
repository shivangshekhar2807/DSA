
#include <iostream>
#include <vector>
using namespace std;

int absDifference(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    if (k > nums.size())
    {
        return -1;
    }

    int s = 0;
    int e = nums.size() - 1;
    int n = 1;

    int max = 0;
    int min = 0;

    while (n <= k)
    {
        max = max + nums[s];
        min = min + nums[e];
        s++;
        e--;
        n++;
    }

    return abs(max - min);
}