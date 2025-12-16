#include <iostream>
#include <vector>
using namespace std;


    void rotate(vector<int> &arr, int k)
    {
        k = k % arr.size();

        int e = arr.size() - 1;

        while (k > 0)
        {

            int val = arr[e];
            int j = arr.size() - 1;
            while (j > 0)
            {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = val;
            k--;
        }
    }



//Better Approach

    void rotate(vector<int> &arr, int k)
    {
        k = k % arr.size();

        reverse(arr.begin(), arr.end());

        reverse(arr.begin(), arr.begin() + k);

        reverse(arr.begin() + k, arr.end());
    }