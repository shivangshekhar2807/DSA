#include <iostream>
#include <vector>
#include <string>
using namespace std;

string countSort(string s)
{
    vector<int> arr(26, 0);
    string ans = "";

    for (char c : s)
    {
        arr[c - 'a']++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] > 0)
        {
            ans += 'a' + i;
            arr[i]--;
        }
    }

    return ans;
}