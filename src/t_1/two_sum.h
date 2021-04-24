#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <vector>
#include <memory>

class TwoSum
{
public:
    virtual std::vector<int> twoSum(std::vector<int>& nums, int target) = 0;

    static std::shared_ptr<TwoSum> create(int tpye);
};

#endif