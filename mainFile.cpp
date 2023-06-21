#include <bits/stdc++.h>
#include <random>
using namespace std;

vector<int> generateTestcase(int n) {
    vector<int> testcase;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-1000, 1000);
    for (int i = 0; i < n; i++) {
        testcase.push_back(dis(gen));
    }
    return testcase;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        // Generate random test case
        int n;
        cin >> n;
        vector<int> a = generateTestcase(n);

        int b[2000];
        int y = 0;

        for (int i = 0; i < n; i++) {
            b[y] = a[i];
            y++;
        }

        int dif;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                dif = abs(abs(a[i]) - abs(a[j]));
                b[y] = dif;
                y++;
            }
        }
        sort(b, b + y);

        int count1 = 0;
        int count2 = 0;
        int k = 0;
        while (k != y) {
            if (b[k] == b[k + 1]) {
                k++;
            } else {
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
    }

    return 0;
}
