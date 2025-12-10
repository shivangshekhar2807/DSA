#include <iostream>
#include <vector>
using namespace std;

int countFreq(vector<int> &arr, int target)
{

    int left = -1;
    int right = -1;

    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == target)
        {
            left = mid;
            e = mid - 1;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    s = 0;
    e = arr.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == target)
        {
            right = mid;
            s = mid + 1;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    if ((left != -1 && right == -1) || (left == -1 && right != -1))
    {
        return 1;
    }

    if (left == -1 && right == -1)
    {
        return 0;
    }

    return (right - left) + 1;
}