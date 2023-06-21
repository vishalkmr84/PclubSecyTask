#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void generateTestCases()
{
    // Initialize random number generator
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    // Define the range for t, n, and the array elements
    uniform_int_distribution<int> tDistribution(1, 10); // Adjust the range as needed
    uniform_int_distribution<int> nDistribution(1, 100); // Adjust the range as needed
    uniform_int_distribution<int> elementDistribution(-1000, 1000); // Adjust the range as needed

    int t = tDistribution(generator);
    cout << t << endl;

    for (int i = 0; i < t; i++)
    {
        int n = nDistribution(generator);
        cout << n << endl;

        int a[n];
        for (int j = 0; j < n; j++)
        {
            int element = elementDistribution(generator);
            cout << element << " ";
        }
        cout << endl;
    }
}

int main()
{
    generateTestCases();
    return 0;
}
