#include <iostream>
#include "partitiongenerator.h"

using namespace std;

namespace comblib {

PartitionGenerator::PartitionGenerator(unsigned int n, bool includeTrivial) :
    n_(n),
    includeTrivial_(includeTrivial),
    end_(false),
    MMax_(n),
    MMin_(n),
    K_(n){
    for (unsigned int i = 0; i < n_; i++) MMin_[i] = 0u;
    for (unsigned int i = 0; i < n_; i++) MMax_[i] = i;
    for (unsigned int i = 0; i < n_; i++) K_[i] = 0u;
}

PartitionGenerator::~PartitionGenerator(){}

bool PartitionGenerator::depleted() const {
    return end_;
}

void PartitionGenerator::generateNext() {
    end_ = true;
    for (unsigned int i = 0; i < n_; i++)
        if (K_[i] != MMax_[i]) {
            end_ = false;
            break;
        }

    for (unsigned i = n_-1; i > 0; --i)
        if (K_[i] <= MMin_[i-1]) {
          K_[i] ++;

          const unsigned nmax = std::max(MMin_[i], K_[i]);
          MMin_[i] = nmax;
          for (unsigned j = i + 1; j < n_; ++j) {
            K_[j] = 0;
            MMin_[j] = MMin_[i];
          }
          break;
        }
}

PartitionGenerator::IntegerSetSet PartitionGenerator::getPartition() const {
    return {};
}

void PartitionGenerator::printForDebug(std::string prefix, std::string suffix) const{
    cout << prefix << "(";

    if (n_ > 0) cout << K_[0];
    for (unsigned int i = 1; i < n_; i++)
        cout << " " << K_[i];


    cout << ")" << suffix;
}

}
