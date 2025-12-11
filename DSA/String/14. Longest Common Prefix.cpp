#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findPrefix(string s, string c)
{
    string ans = "";

    int n = min(s.length(), c.length());

    for (int i = 0; i < n; i++)
    {
        if (s[i] != c[i])
        {
            return ans;
        }
        else
        {
            ans = ans + s[i];
        }
    }
    return ans;
}

string longestCommonPrefix(vector<string> &strs)
{
    string temp = strs[0];

    for (int i = 1; i < strs.size(); i++)
    {
        temp = findPrefix(temp, strs[i]);
    }

    return temp;
}

