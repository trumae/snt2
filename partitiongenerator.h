#ifndef _COMBLIB_PARTITIONGENERATOR_H
#define _COMBLIB_PARTITIONGENERATOR_H

#include <vector>
#include <string>
#include <set>

namespace comblib
{
/**
* Implements an iterator to all possible partitions of a set with a given cardinality.
*
* Examples:
*
* PartitionGenerator part(4);
* while (! part.depleted()) {
*     part.printForDebug("", "\n");
*     part.generateNext();
* }
*
* Prints:
*
* {{0} {1 2 3}}
* {{1} {0 2 3}}
* {{2} {0 1 3}}
* {{3} {0 1 2}}
* {{0} {1} {2 3}}
* {{0} {2} {1 3}}
* {{0} {3} {1 2}}
* {{1} {2} {0 3}}
* {{1} {3} {0 2}}
* {{2} {3} {0 1}}
* {{0} {1} {2} {3}}
*
* NOTE: trivial partition {{}, {0 1 2 3}} is EXCLUDED by default.
*
* getPartition() may be used to get the partition at a given iteration.
*/
class PartitionGenerator
{
public:
    typedef std::set<unsigned int> IntegerSet;
    struct LessThanSet {
        bool operator()(const IntegerSet &a, const IntegerSet &b) const {
            if (a.size() < b.size()) return true;
            if (b.size() < a.size()) return false;
            IntegerSet::const_iterator it1 = a.begin();
            IntegerSet::const_iterator it2 = b.begin();
            while (it1 != a.end()) {
                if ((*it1) < (*it2)) return true;
                if ((*it2) < (*it1)) return false;
                it1++;
                it2++;
            }
            return false;
        }
    };
    typedef std::set<IntegerSet, LessThanSet> IntegerSetSet;
    struct LessThanSetSet {
        bool operator()(const IntegerSetSet &a, const IntegerSetSet &b) const {
            if (a.size() < b.size()) return true;
            if (b.size() < a.size()) return false;
            IntegerSetSet::const_iterator it1 = a.begin();
            IntegerSetSet::const_iterator it2 = b.begin();
            while (it1 != a.end()) {
                PartitionGenerator::LessThanSet comp;
                if (comp((*it1), (*it2))) return true;
                if (comp((*it2), (*it1))) return false;
                it1++;
                it2++;
            }
            return false;
        }
    };
    typedef std::set<IntegerSetSet, LessThanSetSet> IntegerSetSetSet;

    /*
    * includeTrivial = true will include the trivial partition of S: {{}, S}
    */

    PartitionGenerator(unsigned int n, bool includeTrivial = false);
    ~PartitionGenerator();
    bool depleted() const;
    void generateNext();
    IntegerSetSet getPartition() const;
    void printForDebug(std::string prefix, std::string suffix) const;

private:
    void printSet(std::vector<unsigned int> s) const;

    unsigned int n_;
    bool includeTrivial_;
    bool end_;

    std::vector<unsigned int> MMax_;
    std::vector<unsigned int> MMin_;
    std::vector<unsigned int> K_;
};
}
#endif // _COMBLIB_PARTITIONGENERATOR_H
