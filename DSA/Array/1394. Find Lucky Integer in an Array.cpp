#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLucky(vector<int> &arr)
{
    unordered_map<int, int> mp;

    for (int val : arr)
    {
        mp[val]++;
    }

    int max = -1;

    for (auto &p : mp)
    {
        if (p.first == p.second && p.first > max)
        {
            max = p.first;
        }
    }

    return max;
}