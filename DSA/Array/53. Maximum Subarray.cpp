#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &arr)
{
    int max = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int curr = 0;

        for (int j = i; j < arr.size(); j++)
        {
            curr = curr + arr[j];
            if (curr > max)
            {
                max = curr;
            }
        }
    }
    return max;
}