
#include <iostream>
#include <vector>
using namespace std;

vector<int> getMinMax(vector<int> &arr)
{
    int max = INT_MIN;
    int min = INT_MAX;

    vector<int> store;

    for (int val : arr)
    {
        if (val > max)
        {
            max = val;
        }
        if (val < min)
        {
            min = val;
        }
    }
    store.push_back(min);
    store.push_back(max);
    return store;
}