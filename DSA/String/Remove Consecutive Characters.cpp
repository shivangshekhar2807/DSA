
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string removeConsecutiveCharacter(string &s)
{
    string ans;
    ans += s[0];

    if (s.length() == 1)
    {
        return ans;
    }

    for (int i = 1; i < s.length(); i++)
    {
        if (ans.back() == s[i])
        {
            continue;
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}



//Recursive approach

string removeConsecutiveCharacter(const string &s)
{
    if (s.length() <= 0)
    {
        return s;
    }

    string ans = removeConsecutiveCharacter(s.substr(1));

    if (!ans.empty() && s[0] == ans[0])
    {
        return ans;
    }

    ans.insert(ans.begin(), s[0]);

    return ans;
}