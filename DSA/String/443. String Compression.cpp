#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char> &arr)
{

    int ind = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        char s = arr[i];

        int count = 0;

        while (i < arr.size() && arr[i] == s)
        {
            count++;
            i++;
        }

        if (count == 1)
        {
            arr[ind] = s;
            ind++;
        }

        if (count > 1)
        {
            string temp = to_string(count);
            arr[ind] = s;
            ind++;

            for (char c : temp)
            {
                arr[ind] = c;
                ind++;
            }
        }
        i--;
    }

    return ind;
}