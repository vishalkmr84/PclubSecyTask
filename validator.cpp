#include "testlib.h"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int maxT = 100000;
    int maxN = 1000;
    int maxValue = 1000000;
 
    int t = inf.readInt(1, maxT, "t");
    inf.readEoln();
 
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, maxN, "n");
        inf.readEoln();
 
        for (int j = 0; j < n; j++) {
            int a = inf.readInt(-maxValue, maxValue, "a");
            if (j < n - 1)
                inf.readSpace();
        }
        inf.readEoln();
    }
 
    inf.readEof();
    return 0;
}