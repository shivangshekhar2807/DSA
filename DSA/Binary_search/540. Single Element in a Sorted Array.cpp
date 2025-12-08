#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return -1;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        return nums[nums.size() - 1];
    }
    int s = 1;
    int e = nums.size() - 2;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        else if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr;

    int n;

    cout << "Enter n" << endl;

    cin >> n;

    cout << "Enter the value" << endl;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int val = singleNonDuplicate(arr);

    cout << val << endl;
}