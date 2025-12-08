
#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    if (nums.size() == 1 || nums.size() == 0)
    {
        return;
    }
    int stay = 0;
    int move = 1;
    while (move < nums.size())
    {
        if (nums[stay] != 0)
        {
            stay++;
            move++;
        }
        else if (nums[stay] == 0 && nums[move] != 0)
        {
            swap(nums[stay], nums[move]);
            stay++;
            move++;
        }
        else
        {
            move++;
        }
    }
    }
