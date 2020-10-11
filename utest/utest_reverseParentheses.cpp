#include "gtest/gtest.h"
#include <string>

#include "reverseParentheses.h"

namespace reverseParentheses_unit_tests {
class TestReverseParentheses: public testing::Test
{
public:
    virtual void SetUp() override;
    virtual void TearDown() override;
};

void
TestReverseParentheses::SetUp ()
{
}

void
TestReverseParentheses::TearDown ()
{
}

TEST_F(TestReverseParentheses, Simple)
{
    std::string output = reverseParentheses("a(bc)de");
    EXPECT_EQ("acbde", output);
}

TEST_F(TestReverseParentheses, NestedParentheses)
{
    std::string output = reverseParentheses("a(bcdefghijkl(mno)p)q");
    EXPECT_EQ("apmnolkjihgfedcbq", output);
}

TEST_F(TestReverseParentheses, NegTest)
{
    std::string output = reverseParentheses("");
}

TEST_F(TestReverseParentheses, NegTest2)
{
    std::string output = reverseParentheses("(");
}

TEST_F(TestReverseParentheses, NegTest3)
{
    std::string output = reverseParentheses("()");
}

TEST_F(TestReverseParentheses, NegTest4)
{
    std::string output = reverseParentheses("(aabba))");
}

TEST_F(TestReverseParentheses, NegTest5)
{
    std::string output = reverseParentheses("((aabba)cde");
}

TEST_F(TestReverseParentheses, NegTest6)
{
    std::string output = reverseParentheses("((aabba)cd()e");
}

};
