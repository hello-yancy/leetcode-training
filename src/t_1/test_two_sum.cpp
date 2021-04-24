#include "two_sum.h"
#include "gtest/gtest.h"

class TwoSumTest : public testing::Test
{
public:
    virtual void SetUp() {
        m_ptr = TwoSum::create(1);
    }

    virtual void TearDown() {
    }

protected:
    std::shared_ptr<TwoSum> m_ptr;
}

TEST_F(TwoSumTest, test_1)
{
    std::vector<int> rst = m_ptr->twoSum({2, 7, 11, 15}, 9);
    ASSERT_EQ(2, rst.size());
    EXPECT_EQ(0, rst[0]);
    EXPECT_EQ(1, rst[1]);
}
