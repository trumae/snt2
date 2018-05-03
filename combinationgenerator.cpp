#include <iostream>
#include "combinationgenerator.h"

using namespace std;

namespace comblib {

CombinationGenerator::CombinationGenerator(unsigned int n, bool avoidAllZero, bool avoidAllOne):
    status_(n),
    k_(0),
    avoidAllZero_(avoidAllZero),
    avoidAllOne_(avoidAllOne),
    end_(false){
    if (avoidAllZero_)
        generateNext();
}

CombinationGenerator::CombinationGenerator(unsigned int n, unsigned int k) :
    status_(n),
    k_(k),
    end_(false){
    generateNext();
}

CombinationGenerator::~CombinationGenerator() {}

bool CombinationGenerator::at(unsigned int pos) const {
    std::string s = status_.string();
    return s[pos] == '1';
}

bool CombinationGenerator::depleted() const {
    return end_;
}

void CombinationGenerator::generateNext(){
    if (k_ == 0 ) {
        end_ = !status_.inc();
        if(status_.count_ones() == status_.string().length())
            end_ = true;
    } else {
        end_ = !status_.inc();
        while(status_.count_ones() != k_) {
            end_ = !status_.inc();
            if (end_) return;
        }
    }
}

void CombinationGenerator::printForDebug(std::string prefix, std::string suffix) const {
    cout << prefix << "(";

    if (status_.string().length() > 0) cout << status_.string()[0];
    for(size_t i = 1; i < status_.string().length(); i++) {
        cout << " " << status_.string()[i];
    }

    cout << ")" << suffix;
}

}
