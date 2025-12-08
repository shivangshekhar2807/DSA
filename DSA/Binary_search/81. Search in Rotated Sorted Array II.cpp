#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[s] == nums[mid] && nums[mid] == nums[e])
        {
            if (nums[s] == target)
            {
                return true;
            }
            else
            {
                s++;
                e--;
            }
        }
        else if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && nums[mid] >= target)
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
            if (nums[mid] <= target && nums[e] >= target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return false;
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

    cout << "Enter a target value to be serached" << endl;

    int x;

    cin >> x;

    int val = search(arr, x);

    cout << val << endl;
}