#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    string temp;

    for (char c : s)
    {
        if (int(c) >= 97 && int(c) <= 122)
        {
            temp.push_back(c);
        }
        else if (int(c) >= 48 && int(c) <= 57)
        {
            temp.push_back(c);
        }
        else if (int(c) >= 65 && int(c) <= 90)
        {
            char lower = tolower(c);
            temp.push_back(lower);
        }
    }

    int S = 0;
    int e = temp.length() - 1;

    while (S < e)
    {
        if (temp[S] != temp[e])
        {
            return false;
        }
        S++;
        e--;
    }
    return true;
}