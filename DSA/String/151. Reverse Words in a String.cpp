#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s)
{
    reverse(s.begin(), s.end());

    string temp = "";
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        while (i < s.length() && s[i] != ' ')
        {
            temp = temp + s[i];
            i++;
        }

        reverse(temp.begin(), temp.end());
        if (temp.length() > 0)
        {
            ans = ans + " " + temp;
        }

        temp = "";
    }

    if (!ans.empty())
    {
        ans.erase(0, 1);
    }

    return ans;
}