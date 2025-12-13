#include <stack>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &small, vector<int> &big)
{
    vector<int> arr;
    stack<int> st;
    vector<int> ans;
    unordered_map<int, int> mp;

    int i = big.size() - 1;

    while (i >= 0)
    {
        if (st.empty())
        {
            arr.push_back(-1);
            st.push(big[i]);
        }
        else
        {
            if (big[i] < st.top())
            {
                arr.push_back(st.top());
                st.push(big[i]);
            }
            else
            {
                while (!st.empty() && big[i] >= st.top())
                {
                    st.pop();
                }
                if (st.empty())
                {
                    arr.push_back(-1);
                    st.push(big[i]);
                }
                else
                {
                    arr.push_back(st.top());
                    st.push(big[i]);
                }
            }
        }
        i--;
    }
    reverse(arr.begin(), arr.end());

    for (int i = 0; i < big.size(); i++)
    {
        mp[big[i]] = arr[i];
    }

    for (int x : small)
    {
        ans.push_back(mp[x]);
    }

    return ans;
}