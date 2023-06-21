#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int b[2000];
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            b[y] = a[i];
            y++;
        }
        int dif;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                dif = abs(abs(a[i]) - abs(a[j]));
                b[y] = dif;
                y++;
            }
        }
        sort(b, b + y);
        int count1 = 0;
        int count2 = 0;
        int k = 0;
        while (k != y)
        {
            if (b[k] == b[k + 1])
            {
                k++;
            }
            else
            {
                if (b[k] % 2 == 0 && b[k] > 0)
                    count1++;
                else if (b[k] % 2 != 0 && b[k] > 0)
                    count2++;
                k++;
            }
        }
        if (count1 >= n || count2 >= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        // Checker code
        bool isValid = true;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = abs(abs(a[i]) - abs(a[j]));
                bool found = false;
                for (int k = 0; k < y; k++)
                {
                    if (b[k] == diff)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    isValid = false;
                    break;
                }
            }
            if (!isValid)
                break;
        }
        if (isValid)
            cout << "Checker: Passed" << endl;
        else
            cout << "Checker: Failed" << endl;
    }
    return 0;
}
