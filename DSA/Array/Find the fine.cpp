#include <iostream>
#include <vector>
using namespace std;
long long int totalFine(int date, vector<int> &car, vector<int> &fine)
{
    long long int total = 0;

    if (date % 2 == 0)
    {
        for (int i = 0; i < car.size(); i++)
        {
            if (car[i] % 2 != 0)
            {
                total = total + fine[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < car.size(); i++)
        {
            if (car[i] % 2 == 0)
            {
                total = total + fine[i];
            }
        }
    }

    return total;
}