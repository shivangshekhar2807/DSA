
#include <iostream>
#include <vector>
using namespace std;

void segregateElements(vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;

    for (int val : arr)
    {
        if (val < 0)
        {
            neg.push_back(val);
        }
        else
        {
            pos.push_back(val);
        }
    }

    int i;

    for (i = 0; i < pos.size(); i++)
    {
        arr[i] = pos[i];
    }

    int j = i;

    for (int k = 0; k < neg.size(); k++)
    {
        arr[j] = neg[k];
        j++;
    }
}