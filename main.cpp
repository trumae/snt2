#include <iostream>
#include <cmath>

#include "stringbin.h"
#include "combinationgenerator.h"

using namespace std;
using namespace comblib;

void testStringBin(int n) {
    stringbin b(n);

    cout << b.string() << endl;
    for (int i = 0; i < exp2(n); i++) {
        bool ok = b.inc();
        cout << b.string() << " - " << ok << " ones: " << b.count_ones() << endl;
    }
}

int main()
{
    testStringBin(4);
    testStringBin(10);

    cout << "comb(3)" << endl;
    CombinationGenerator comb(3);
    while (! comb.depleted()) {
        comb.printForDebug("", "\n");
        comb.generateNext();
    }

    cout << endl << "comb(3,true)" << endl;
    CombinationGenerator comb2(3, true);
    while (! comb2.depleted()) {
        comb2.printForDebug("", "\n");
        comb2.generateNext();
    }

    cout << endl << "comb(3,true, true)" << endl;
    CombinationGenerator comb3(3, true, true);
    while (! comb3.depleted()) {
        comb3.printForDebug("", "\n");
        comb3.generateNext();
    }

     cout << endl << "comb(5, 3)" << endl;
    CombinationGenerator comb52(5u, 3u);
    while (! comb52.depleted()) {
      comb52.printForDebug("", "\n");
      comb52.generateNext();
    }
    
    return 0;
}

