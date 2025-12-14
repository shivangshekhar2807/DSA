#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target)
{
    if (arr.empty())
        return false;
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        vector<int> &temp = arr[mid];

        int first = 0;

        int last = temp.size() - 1;

        if (target >= temp[first] && target <= temp[last])
        {
            while (first <= last)
            {
                int m = (first + last) / 2;

                if (target == temp[m])
                {
                    return true;
                }
                else if (target > temp[m])
                {
                    first = m + 1;
                }
                else
                {
                    last = m - 1;
                }
            }
            return false;
        }

        else if (target < temp[first])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return false;
}