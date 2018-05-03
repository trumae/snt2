#ifndef _COMBLIB_COMBINATIONGENERATOR_H
#define _COMBLIB_COMBINATIONGENERATOR_H

#include <string>
#include "stringbin.h"

namespace comblib {
/**
* Implements an iterator to all the combinations of N elements of a set taken K
* by K.
*
* Examples:
*
* CombinationGenerator comb(3);
* while (! comb.depleted()) {
*   comb.printForDebug("", "\n");
*   comb.generateNext();
* }
*
* Prints:
*
* (0 0 0)
* (1 0 0)
* (0 1 0)
* (1 1 0)
* (0 0 1)
* (1 0 1)
* (0 1 1)
* (1 1 1)
*
* CombinationGenerator comb(5, 3);
* while (! comb.depleted()) {
*   comb.printForDebug("", "\n");
*   comb.generateNext();
* }
*
* Prints:
*
* (1 1 1 0 0)
* (1 1 0 1 0)
* (1 0 1 1 0)
* (0 1 1 1 0)
* (1 1 0 0 1)
* ...
* ...
* (0 0 1 1 1)
*
* At any iteration one may use at(pos) to check whether a given element is selected
* for that iteration or not.
*
* CombinationGenerator comb(5, 3);
* comb.printForDebug("", "\n");
* printf("%s\n", (comb.at(0) ? "TRUE" : "FALSE"));
* printf("%s\n", (comb.at(3) ? "TRUE" : "FALSE"));
*
* Prints:
*
* (1 1 1 0 0)
* TRUE
* FALSE
*/

class CombinationGenerator {
public:
/*
 * avoidAllZero = true excludes the element (0 0 ... 0)
 * avoidAllOne = true excludes the element (1 1 ... 1)
 */
    CombinationGenerator(unsigned int n, bool avoidAllZero = false, bool avoidAllOne = false);
    CombinationGenerator(unsigned int n, unsigned int k);
    ~CombinationGenerator();
    bool at(unsigned int pos) const;
    bool depleted() const;
    void generateNext();
    void printForDebug(std::string prefix, std::string suffix) const;

private:
    stringbin status_;
    int k_;
    bool avoidAllZero_;
    bool avoidAllOne_;
    bool end_;
};

}

#endif // _COMBLIB_COMBINATIONGENERATOR_H

