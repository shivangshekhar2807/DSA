#include <iostream>
#include <vector>
using namespace std;


//Sorting

bool containsDuplicate(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    if (arr.size() == 1)
    {
        return false;
    }

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            return true;
        }
    }
    return false;
}


// Double loop

bool containsDuplicate(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}



//Unordered map

bool containsDuplicate(vector<int> &arr)
{
    unordered_map<int, int> mp;

    for (int val : arr)
    {
        mp[val]++;
    }

    for (auto &p : mp)
    {
        if (p.second > 1)
        {
            return true;
        }
    }
    return false;
}
