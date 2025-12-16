#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    if (arr2.size() == 0)
    {
        return;
    }
    int s = 0;

    while (s < m)
    {
        if (arr1[s] > arr2[0])
        {
            swap(arr1[s], arr2[0]);

            s++;
        }
        else
        {
            s++;
        }
    }
    int i = 0;

    while (s < arr1.size())
    {
        arr1[s] = arr2[i];
        s++;
        i++;
    }
}