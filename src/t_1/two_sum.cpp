#include "two_sum.h"

class TwoSumImpl_1 : public TwoSum
{
public:
    virtual std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return std::vector<int>();
    }
};

class TwoSumImpl_2 : public TwoSum
{
public:
    virtual std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        return std::vector<int>();
    }
};

std::shared_ptr<TwoSum> TwoSum::create(int type)
{
    switch (type) {
        case 1:
            return std::make_shared<TwoSumImpl_1>();
        case 2:
            return std::make_shared<TwoSumImpl_2>();
        default:
            return nullptr;
    }
}
