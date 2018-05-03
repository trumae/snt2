#include "stringbin.h"

using namespace std;

stringbin::stringbin(int n) {
    for (int i =0; i < n; i++)
        data_ += "0";
}

bool stringbin::inc() {
    int n = data_.length();

    for (int i = 0; i < n; i++) {
        if (data_[i] == '0') {
            data_[i] = '1';
            return true;
        }
        data_[i] = '0';
    }

    return false;
}

int stringbin::count_ones() const {
    int count = 0;
    for (auto c: data_) {
        if (c == '1') count ++;
    }
    return count;
}
