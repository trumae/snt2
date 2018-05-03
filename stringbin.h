#ifndef STRINGBIN_H
#define STRINGBIN_H

#include <string>

class stringbin
{
public:
    stringbin(){};
    stringbin(int n);

    bool inc();
    std::string string() const { return data_; }
    int count_ones() const;
public:
    std::string data_;
};

#endif // STRINGBIN_H
