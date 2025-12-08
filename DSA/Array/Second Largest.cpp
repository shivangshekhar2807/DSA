
#include <iostream>
#include <vector>
using namespace std;
int getSecondLargest(vector<int> &arr)
{
    int first = -1;
    int second = -1;

    for (int c : arr)
    {
        if (c > first)
        {
            if (first > second)
            {
                second = first;
            }
            first = c;
        }
        else if (c > second && c != first)
        {
            second = c;
        }
    }

    return second;
}