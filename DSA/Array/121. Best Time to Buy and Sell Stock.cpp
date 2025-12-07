#include <iostream>
#include <vector>
using namespace std;

int buyStock(vector<int> prices)
{
    int buy = prices[0];

    int max = 0;
    int i = 1;

    while (i < prices.size())
    {
        int pro = prices[i] - buy;

        if (pro > max)
        {
            max = pro;
        }

        if (buy > prices[i])
        {
            buy = prices[i];
        }

        i++;
    }
    return max;
}

int main()
{
    vector<int> arr;

    int n;

    cout << "Enter n" << endl;

    cin >> n;

    cout << "Enter the value" << endl;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int val = buyStock(arr);

    cout << val << endl;
}