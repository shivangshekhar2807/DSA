#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &arr)
{
    int zero = 0;
    int two = arr.size() - 1;
    int move = 0;

    while (move <= two)
    {
        if (arr[move] == 0)
        {
            swap(arr[move], arr[zero]);
            zero++;
            move++;
        }
        else if (arr[move] == 2)
        {
            swap(arr[move], arr[two]);
            two--;
        }
        else
        {
            move++;
        }
    }
}