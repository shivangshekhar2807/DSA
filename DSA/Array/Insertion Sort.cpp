#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i];
        int pre = i - 1;

        while (pre >= 0)
        {
            if (curr < arr[pre])
            {
                arr[pre + 1] = arr[pre];
                pre--;
            }
            else
            {
                break;
            }
        }
        arr[pre + 1] = curr;
    }
}